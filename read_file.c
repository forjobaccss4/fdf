/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:12:50 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:12:52 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		make_int_arr(t_lst *new, char **line)
{
	int counter;

	counter = -1;
	if (!(new->int_arr[new->counter] = malloc(sizeof(int) * new->width + 1)))
		return ;
	while (line[++counter])
		new->int_arr[new->counter][counter] = ft_atoi(line[counter]);
	if (line != NULL)
		free_d_arr(line);
	new->counter += 1;
}

void		read_map(t_lst *new, int fd)
{
	char		*line;
	int			counter;

	counter = 0;
	while ((counter = get_next_line(fd, &line)) > 0)
	{
		if (counter == -1)
			err_msg("Error\n");
		if (ft_isdigit(line[0]) == 0 && line[0] != ' ')
		{
			if (ft_isdigit(line[1]) == 0)
			{
				free(line);
				err_msg("Error\n");
			}
		}
		make_int_arr(new, ft_strsplit(line, ' '));
		free(line);
	}
}
