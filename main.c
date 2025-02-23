/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:07:51 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/23 13:51:44 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

static void	open_infile(t_data *data, char **av)
{
	data->f_in = open(av[1], O_RDONLY);
	if (data->f_in == -1)
	{
		perror("Error file in");
		exit(2);
	}
}

static void	open_outfile(t_data *data, char **av)
{
	data->f_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->f_out == -1)
	{
		perror("Error file out");
		exit(2);
	}
}

static void	check_infile_size(t_data *data, char **av)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes;
	ssize_t	total;

	total = 0;
	while (1)
	{
		bytes = read(data->f_in, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		total += bytes;
		if (total > MAX_ALLOWED)
		{
			ft_putstr_fd("Error: infile is too big\n", 2);
			close(data->f_in);
			exit(2);
		}
	}
	close(data->f_in);
	open_infile(data, av);
}

void	init_data(t_data *data, char **env, char **av)
{
	open_infile(data, av);
	check_infile_size(data, av);
	open_outfile(data, av);
	data->av = &av[1];
	data->env = env;
	processes_making(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac == 5)
		init_data(&data, env, av);
	else
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(2);
	}
	return (0);
}
