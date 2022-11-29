/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:40:30 by nickras           #+#    #+#             */
/*   Updated: 2022/11/29 13:18:43 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//writes a char to stdout
int	handle_char(int i)
{
	unsigned char	c;

	c = i;
	return (write(1, &c, 1));
}

//writes string to stdout
int	handle_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

//writes decimal to stdout
int	handle_decimal(int i)
{
	int		length;
	long	newint;

	newint = (long)i;
	length = 0;
	if (newint < 0)
	{
		length += write(1, "-", 1);
		newint = -newint;
	}
	if (newint / 10)
		length += handle_decimal(newint / 10);
	newint = newint % 10 + '0';
	length += handle_char(newint);
	return (length);
}

//writes unsigned integer to stdout by convering integer to ascii value
int	ft_uitoa(unsigned int n)
{
	int		length;
	long	newint;

	newint = (long)n;
	length = 0;
	if (newint / 10)
		length += handle_decimal(newint / 10);
	newint = newint % 10 + '0';
	length += handle_char(newint);
	return (length);
}

//main function used for testing
/* int main() {
ft_hexa(1234567);
  return 0;
} */