/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:32:04 by abreuil           #+#    #+#             */
/*   Updated: 2024/09/03 13:38:34 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < dstsize)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dest_len + i) < (dstsize - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len < dstsize)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
