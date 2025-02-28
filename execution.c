/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:30:04 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/28 18:36:26 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static void	child_process_one(t_data *data)
{
	close(data->fd[0]);
	if (dup2(data->f_in, STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit(2);
	}
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(2);
	}
	close(data->fd[1]);
	close(data->f_in);
	close(data->f_out);
	execute(data->av[1], data);
	exit(1);
}

static void	child_process_two(t_data *data)
{
	close(data->fd[1]);
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit(2);
	}
	if (dup2(data->f_out, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(2);
	}
	close(data->fd[0]);
	close(data->f_out);
	close(data->f_in);
	execute(data->av[2], data);
	exit(1);
}

static void	parent_cleanup(t_data *data, pid_t pid1, pid_t pid2)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->f_in);
	close(data->f_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

static	pid_t	create_second_child(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(2);
	}
	if (pid == 0)
		child_process_two(data);
	return (pid);
}

void	processes_making(t_data *data)
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(data->fd) < 0)
	{
		perror("pipe error");
		exit(2);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork error");
		exit(2);
	}
	if (pid1 == 0)
	{
		child_process_one(data);
	}
	pid2 = create_second_child(data);
	parent_cleanup(data, pid1, pid2);
}
