/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:00:21 by abreuil           #+#    #+#             */
/*   Updated: 2024/09/25 15:13:20 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	trim_size;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && ft_isset(s[start], set) == 1)
		start++;
	end = ft_strlen(s);
	while (end > start && ft_isset(s[end - 1], set) == 1)
		end--;
	trim_size = end - start;
	trimmed = malloc(trim_size + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s[start], trim_size + 1);
	return (trimmed);
}

/*int main() 
{
    // Test cases for ft_strtrim
    const char *test1 = "   Hello, World!   ";
    const char *test2 = "NoSpaces";
    const char *test3 = "      ";
    const char *test4 = "\t  Trimming\tExample  \n";
    
    // Trimming results
    char *result1 = ft_strtrim(test1, " ");
    char *result2 = ft_strtrim(test2, " ");
    char *result3 = ft_strtrim(test3, " ");
    char *result4 = ft_strtrim(test4, " ");

    // Print results
    printf("Original: \"%s\" -> Trimmed: \"%s\"\n", test1, result1);
    printf("Original: \"%s\" -> Trimmed: \"%s\"\n", test2, result2);
    printf("Original: \"%s\" -> Trimmed: \"%s\"\n", test3, result3);
    printf("Original: \"%s\" -> Trimmed: \"%s\"\n", test4, result4);

    // Free allocated memory
    free(result1);
    free(result2);
    free(result3);
    free(result4);

    return 0;
}*/