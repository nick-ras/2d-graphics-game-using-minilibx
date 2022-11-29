/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:15:24 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/11/29 14:32:20 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//My own implementation of the C library function 
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*concat;
	size_t		count;
	size_t		lenconcat;

	lenconcat = 0;
	count = 0;
	if (!s1)
		return (NULL);
	while (s1[count++] != '\0')
		lenconcat++;
	count = 0;
	while (s2[count++] != '\0')
		lenconcat++;
	concat = malloc(sizeof(char) * (lenconcat + 1));
	if (!concat)
		return (NULL);
	ft_memcpy(concat, s1, ft_strlen(s1));
	ft_memcpy(concat + ft_strlen(s1), s2, ft_strlen(s2));
	concat[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (concat);
}

/* int	main(void)
{
	char s1[] = "1234";
	char s2[] = "22";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
} */
