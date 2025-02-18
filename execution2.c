/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:39:16 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/17 20:53:52 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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
	ft_strlcpy(ptr, &env[i][j], ft_strlen(&env[i][j]) + 1);
	data->path = ft_split(ptr, ':');
	free(ptr);
}

void	execute(char *cmd, t_data *data)
{
	int		i;
	char	*pth_cmd;
	char	*hold;

	i = 0;
	get_path(data, data->env);
	data->cmd_opt = ft_split(cmd, ' ');
	while (data->path[i])
	{
		hold = ft_strjoin("/", data->cmd_opt[0]);
		pth_cmd = ft_strjoin(data->path[i], hold);
		if (!access(pth_cmd, F_OK))
		{
			if (!access(pth_cmd, X_OK))
				execve(pth_cmd, data->cmd_opt, data->env);
			else
				perror("Permission Denied: /\n");
		}
		free(hold);
		free(pth_cmd);
		i++;
	}
	perror("Invalid Command: /\n");
	exit(1);
}
