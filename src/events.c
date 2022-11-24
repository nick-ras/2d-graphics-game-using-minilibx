#include "../so_long.h"

int	no_event(void *data)
{
	(void) data;
	return (EXIT_SUCCESS);
}

void	result(t_map *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr); //the init and new windows create win_ptr
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->winner,
		data->columns * 40 / 2.4, data->rows * 40 / 4);
}

int free_map(t_map *grid, int exit_func)
{
	int	i;

	i = 0;
	while (i < grid->rows)
	{
		if (grid->map[i] != NULL)
			free(grid->map[i]);
		if (grid->map[i] != NULL)
			free(grid->map2[i]);
		i++;
	}
	free(grid->map);
	free(grid->map2);
	free(grid);
	if (exit_func)
	{
		ft_printf("exits program with error\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}