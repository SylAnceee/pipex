/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:30:04 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/20 21:01:36 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	processes_making(t_data *data)
{
	if (pipe(data->fd) < 0)
		perror("pipe error\n");
	data->proc = fork();
	if (data->proc < 0)
	{
		perror("fork error\n");
		exit(2);
	}
	if (data->proc == 0)
	{
		close(data->fd[0]);
		dup2(data->f_in, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		execute(data->av[1], data);
	}
	if (data->proc > 0)
	{
		wait(0);
		close (data->fd[1]);
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->f_out, STDOUT_FILENO);
		execute(data->av[2], data);
	}
}
