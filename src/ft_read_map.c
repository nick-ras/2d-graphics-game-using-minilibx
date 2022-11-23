
#include "../so_long.h"

void	ft_map_hight(t_map *data)
{
	char		*line;
	int			fd;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("File not read\n");
		exit (EXIT_FAILURE);
	}
	while (line[data->columns] != '\0')
		data->columns++;
	while (line)
	{
		if ((int)ft_strlen(line) != data->columns)
		{
			printf("Error.Map not valide");
			exit(EXIT_FAILURE);
		}
		data->rows++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_read_map(t_map *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
	i = 0;
	while (line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	line = NULL;
	close(fd);
}