/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:20:21 by nickras           #+#    #+#             */
/*   Updated: 2022/05/18 12:08:58 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Werror -Wextra -Wall ft_split.c ft_substr.c && ./a.out */

#include "libft.h"

//calculates substring by counting the amount of times the 
//delimiter "c" comes up
static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
		}
	}
	return (words);
}

//Calculates the amount of bytes for each array and put each string in each substring of the 2d array
static char	**create_substrings(char const *s, char	**str2d, char c)
{
	unsigned int	i;
	unsigned int	wordlength;
	unsigned int	index;

	wordlength = 0;
	index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			wordlength++;
			i++;
		}
		if (wordlength > 0)
		{
			str2d[index] = ft_substr(s, i - wordlength, (size_t)wordlength);
			index++;
		}
		wordlength = 0;
	}
	return (str2d);
}

//My own implementation of the C library function.
//The functions makes a 2d array and uses subfunction to put the values into the substrings
char	**ft_split(char const *s, char c)
{
	char	**str2d;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str2d = ft_calloc(words + 1, sizeof(char *));
	if (!str2d || words == 0)
		return (str2d);
	str2d[words] = NULL;
	str2d = create_substrings(s, str2d, c);
	return (str2d);
}

/* int	main(void)
{
	char	s[] = "  tripouille  42  ";
	char	c = ' ';

	ft_split(s, c);
	return (0);
}
 */