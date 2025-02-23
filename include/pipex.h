/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:09:18 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/23 13:36:02 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 4096
# define MAX_ALLOWED 4096

# include <unistd.h> // fork, execve, pipe
# include <stdlib.h> // malloc
# include <stdio.h> // perror
# include <fcntl.h> // open
# include <string.h> // strerror
# include <sys/wait.h> // open
# include <signal.h>
# include <errno.h>
# include "../libft/libft.h" 

typedef struct s_cmd
{
	char			*cmd; // stores full commands strings
	struct s_cmd	*next;
	int				f_in; // stdint
	int				f_out; //stdout
}	t_cmd;

typedef struct s_data
{
	char	**av; // stores every agrument passed to the program
	char	**env; // stores the environment variables used to access the PATH
	char	**path; // holds the directories from the PATH variable
	char	**cmd_opt; // stores the command and its options
	int		proc; // tracks number of processes or acts as PID
	int		fd[2]; //file descriptors for a pipe
	int		f_in; // input file
	int		f_out; //output file
	t_cmd	*cmd; // Pointer to linked list rpz cmds int pipeline
}	t_data;

void	processes_making(t_data *data);
void	execute(char *cmd, t_data *data);

#endif