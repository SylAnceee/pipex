/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:09:18 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/28 16:53:52 by abreuil          ###   ########.fr       */
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
	char			*cmd;
	struct s_cmd	*next;
	int				f_in;
	int				f_out;
}	t_cmd;

typedef struct s_data
{
	char	**av;
	char	**env;
	char	**path;
	char	**cmd_opt;
	int		proc;
	int		fd[2];
	int		f_in;
	int		f_out;
	t_cmd	*cmd;
}	t_data;

void	processes_making(t_data *data);
void	execute(char *cmd, t_data *data);

#endif