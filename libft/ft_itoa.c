/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:29:51 by abreuil           #+#    #+#             */
/*   Updated: 2024/09/05 13:14:15 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int nb)
{
	int	counter;

	counter = 0;
	if (nb <= 0)
		counter++;
	while (nb != 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/*int	main(void)
{
	int		numbers[] = {0, 123, -456, 7890, -2147483648, 2147483647};
	size_t	size = sizeof(numbers) / sizeof(numbers[0]);
	size_t	i;
	char	*str;

	i = 0;
	while (i < size)
	{
		str = ft_itoa(numbers[i]);
		if (str)
		{
			printf("Integer: %d, String: %s\n", numbers[i], str);
			free(str);
		}
		else
		{
			printf("Conversion failed for integer: %d\n", numbers[i]);
		}
		i++;
	}
	return (0);
}
*/