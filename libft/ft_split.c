/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:21:50 by abreuil           #+#    #+#             */
/*   Updated: 2024/09/25 15:28:54 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char sep)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i] != sep && s[i])
			words++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (words);
}

char	*dup_str(char const *s, char sep)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] != sep && s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[i] = dup_str(s, c);
			if (!tab)
				return (NULL);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
/*(int	is_sep(const char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	num_words(const char *str, const char *charset)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
			wordcount++;
		i++;
	}
	return (wordcount);
}

void	free_tab(char **tab, int words_allocated)
{
	int i = 0;
	while (i < words_allocated)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(const char *s, const char *charset)
{
	char	**tab;
	int		words;
	int		word;
	size_t	i;
	size_t	j;

	if (!s || !charset)
		return (NULL);

	words = num_words(s, charset);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);

	word = 0;
	i = 0;
	while (s[i])
	{
		if (!is_sep(s[i], charset))
		{
			j = 0;
			while (s[i + j] && !is_sep(s[i + j], charset))
				j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab[word])
			{
				free_tab(tab, word); 
				return (NULL);
			}
			ft_memcpy(tab[word], &s[i], j); 
			tab[word][j] = '\0';
			word++;
			i += j;
		}
		else
			i++;
	}
	tab[word] = NULL;  // Null-terminate the array of strings
	return (tab);
}
*/