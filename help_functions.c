/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:16:45 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/24 12:16:47 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook_esc(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int		exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

char	**save_cycle(int gnl, int fd, char *line, char **map_arr)
{
	int i;

	i = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		map_arr[i] = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1));
		map_arr[i][ft_strlen(line)] = '\0';
		ft_strcpy(map_arr[i], line);
		free(line);
		i++;
	}
	return (map_arr);
}

int		**coordinates(char **map)
{
	int		i;
	int		j;
	int		**int_map;
	char	**tmp;

	tmp = NULL;
	j = -1;
	i = len_d_arr(map);
	int_map = (int**)malloc(sizeof(int*) * (i + 1));
	int_map[i] = NULL;
	while (map[++j])
	{
		tmp = coordinates_in_one_line(map[j]);
		int_map[j] = (int*)malloc(sizeof(int) * len_d_arr(tmp));
		i = -1;
		while (++i < len_d_arr(tmp))
			int_map[j][i] = ft_atoi(tmp[i]);
		free_double_array(tmp);
	}
	return (int_map);
}

void	drow(char **map, int **int_map, t_lst *win)
{
	int *xytxtywhc;

	int_map = NULL;
	xytxtywhc = (int*)malloc(sizeof(int) * 7);
	xytxtywhc[4] = len_of_map(map[0]);
	xytxtywhc[5] = len_d_arr(map);
	xytxtywhc[1] = 500 + (((xytxtywhc[5]) / 2) * 20);
	xytxtywhc[0] = 500 - ((xytxtywhc[4] / 2) * 20);
	while (xytxtywhc[5] - 1)
	{
		xytxtywhc[6] = -1;
		xytxtywhc[0] = 500 - ((xytxtywhc[4] / 2) * 20);
		while (++xytxtywhc[6] < (xytxtywhc[4] - 1))
		{
			line(win, xytxtywhc, xytxtywhc[0] + 20, xytxtywhc[1]);
			line(win, xytxtywhc, xytxtywhc[0], xytxtywhc[1] + 20);
			xytxtywhc[0] += 20;
		}
		xytxtywhc[1] -= 20;
		xytxtywhc[5]--;
	}
	drow_helper(xytxtywhc, map, win);

}

void	drow_helper(int *xytxtywhc, char **map, t_lst *win)
{
	xytxtywhc[0] = 500 - ((xytxtywhc[4] / 2) * 20);
	xytxtywhc[1] = 520 + (((len_d_arr(map)) / 2) * 20);
	xytxtywhc[2] = (xytxtywhc[0] - 20) + (xytxtywhc[4] * 20);
	xytxtywhc[3] = (xytxtywhc[1] + 20) - (len_d_arr(map)* 20);
	line(win, xytxtywhc, xytxtywhc[2], xytxtywhc[1]);
	xytxtywhc[0] = xytxtywhc[2];
	line(win, xytxtywhc, xytxtywhc[2], xytxtywhc[3]);
	free(xytxtywhc);
}
