/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:29:40 by nick              #+#    #+#             */
/*   Updated: 2022/11/25 13:49:11 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	filename_check(char *map)
{
	char	*ptr;

	if (ft_strnstr(map, ".ber", ft_strlen(map)) == NULL)
	{
		ft_printf("name not correct\n");
		exit (1);
	}
	ptr = ft_memchr(map, '.', ft_strlen(map));
	if (*(ptr + 4) != '\0')
	{
		ft_printf("char after '.ber'\n");
		exit (1);
	}
	if (ptr == map)
	{
		ft_printf("char(s) missing before '.ber'\n");
		exit (1);
	}
}
	//ft_printf("name %s length%d \n", map, ft_strlen(map));

int	get_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd error from first open\n");
		exit (1);
	}
	return (fd);
}

void	set_columns(t_map *grid, char *line_as_str)
{
	int	i;

	i = 0;
	while (line_as_str[i] != '\n' && line_as_str[i] != '\0')
		i++;
	grid->columns = i;
	ft_printf("grid->columns %d\n", grid->columns);
}
