/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:43:53 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/17 22:11:25 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//My own implementation of the C library function 
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*target;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start > ft_strlen(s))
		len = 0;
	else if (len + (size_t)start > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	target = malloc(sizeof(*s) * (len + 1));
	if (!target)
		return (NULL);
	while (i < len)
	{
		target[i] = s[start + i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

/* int	main(void)
{
	char s[] = "tripouille";
	unsigned int start;
	size_t len;
	
	start = 0;
	len = 42000;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/
