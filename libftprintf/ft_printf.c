/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:55:54 by nickras           #+#    #+#             */
/*   Updated: 2022/11/29 13:19:32 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//This function detects what kind of conversion it needs to do and sends it to
//the right subfunction. The subfunction write to stdout, and return the amount 
//of bytes it wrote in stdout
int	handler(const char *s, int i, va_list args)
{
	int	length;

	length = 0;
	if (s[i] == '%')
		length += handle_char('%');
	else if (s[i] == 'c')
		length += handle_char(va_arg(args, int));
	else if (s[i] == 's')
		length += handle_string(va_arg(args, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		length += handle_decimal(va_arg(args, int));
	else if (s[i] == 'u')
		length += ft_uitoa(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		length += ft_hexa(va_arg(args, unsigned int));
	else if (s[i] == 'X')
		length += ft_hexau(va_arg(args, unsigned int));
	else if (s[i] == 'p')
		length += ft_hexaul(va_arg(args, unsigned long));
	else
		length += write(1, "%", 1);
	return (length);
}

//This functions is the starting function. It does mostly the same as 
// the original printf but use write statement. 
// It takes a string and a variable amount of command line argument. 
// Everytime there is a "%" in the string, it will go into subfunction that 
// handles conversions and write to stdout, just like
//in printf (see man)
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		slen;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	slen = (int)ft_strlen(s);
	while (i < slen && slen > 0)
	{
		if (s[i] == '%')
		{
			i++;
			length += handler(s, i, args);
		}
		else
			length += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}
