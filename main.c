/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:12:45 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:14:14 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			add_struct(t_lst *new)
{
	new->trigger = 1;
	new->mlx_ptr = NULL;
	new->win_ptr = NULL;
	new->int_arr = NULL;
	new->width = 0;
	new->height = 0;
	new->counter = 0;
	new->z = 0;
	new->x = 0;
	new->y = 0;
	new->next_x = 0;
	new->next_y = 0;
}

void			compare_length_of_line(char *line, t_lst *new)
{
	char	**splited;
	int		i;

	i = -1;
	splited = ft_strsplit(line, ' ');
	while (splited[++i])
		;
	if (new->height == 0)
		new->width = i;
	if (i != new->width)
		err_msg("Error\n");
	free_d_arr(splited);
}

void			count_create_int_arr(t_lst *new, int fd)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	new->height = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		compare_length_of_line(line, new);
		free(line);
		i++;
		new->height = i;
	}
	if (!(new->int_arr = (int**)malloc(sizeof(int*) * (i))))
		exit(1);
}

int				main(int argc, char **argv)
{
	t_lst	*new;
	int		fd;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	if (argc != 2)
		err_msg("usage: ./fdf [map.fdf]\n");
	fd = open(argv[1], O_DIRECTORY);
	if (fd >= 0)
		err_msg("usage: ./fdf [map.fdf]\n");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		err_msg("usage: ./fdf [map.fdf]\n");
	else
	{
		add_struct(new);
		count_create_int_arr(new, fd);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	read_map(new, fd);
	window_creator(new, argv[1]);
	free_structure(new);
	close(fd);
	return (0);
}
