/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:39:16 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/19 18:34:12 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	handle_execve_error(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i])
		free(data->path[i++]);
	free(data->path);
	i = 0;
	while (data->cmd_opt[i])
		free(data->cmd_opt[i++]);
	free(data->cmd_opt);
	close(data->f_in);
	close(data->f_out);
	close(data->fd[0]);
	close(data->fd[1]);
	exit(127);
}

void	get_path(t_data *data, char **env)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 5;
	while (env[i] && ft_strncmp(env[i], "PATH=", j))
		i++;
	if (!env[i])
		exit(2);
	ptr = ft_calloc(ft_strlen(&env[i][j]) + 1, sizeof(char));
	if (!ptr)
		return ;
	ft_strlcpy(ptr, &env[i][j], ft_strlen(&env[i][j]) + 1);
	data->path = ft_split(ptr, ':');
	free(ptr);
}

void	execute(char *cmd, t_data *data)
{
	int		i;
	char	*pth_cmd;
	char	*temp;

	if (!cmd || !*cmd)
		exit(126);
	i = 0;
	get_path(data, data->env);
	data->cmd_opt = ft_split(cmd, ' ');
	while (data->path[i])
	{
		temp = ft_strjoin("/", data->cmd_opt[0]);
		pth_cmd = ft_strjoin(data->path[i], temp);
		if (!access(pth_cmd, F_OK | X_OK))
		{
			execve(pth_cmd, data->cmd_opt, data->env);
			free(temp);
			free(pth_cmd);
			handle_execve_error(data);
		}
		free(temp);
		free(pth_cmd);
		i++;
	}
	handle_execve_error(data);
}
