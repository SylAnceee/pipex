/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:07:51 by abreuil           #+#    #+#             */
/*   Updated: 2025/02/19 18:34:32 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac == 5)
	{
		data.f_in = open(av[1], O_RDONLY);
		if (data.f_in == -1)
		{
			perror("Error file in\n");
			exit(2);
		}
		data.f_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data.f_out == -1)
		{
			perror("Error file out\n");
			exit(2);
		}
		data.av = &av[1];
		data.env = env;
		processes_making(&data);
	}
	else
	{
		perror("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit(2);
	}
}
