#include "fdf.h"

char	**save_map(char *rgv)
{
	int		fd;
	int		counter;
	int		gnl;
	char 	*line;
	char 	**map_arr;

	counter = 0;
	map_arr = NULL;
	fd = open(rgv, O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		free(line);
		counter++;
	}
	close(fd);
	if (!(map_arr = (char**)malloc(sizeof(char*) * (counter + 1))))
		return (NULL);
	map_arr[counter] = 0;
	fd = open(rgv, O_RDONLY);
	map_arr = save_cycle(gnl, fd, line, map_arr);
	close(fd);
	return (map_arr);
}

int main(int argc, char **argv)
{
	t_lst	*win;
	char 	**map_arr;
	int		**int_arr;

	if (argc < 2)
		return (0);
	win = (t_lst*)malloc(sizeof(t_lst));
	map_arr = save_map(argv[1]);
	int_arr = coordinates(map_arr);
	win->mlx_ptr = mlx_init();
	win->win_prt = mlx_new_window(win->mlx_ptr, 1000, 1000, "new window");
	drow(map_arr, int_arr, win);
	mlx_key_hook(win->win_prt, key_hook_esc, NULL);
	mlx_hook(win->win_prt, 17, 1L << 0, exit_x, NULL);
	mlx_loop(win->mlx_ptr);
	return (0);
}
