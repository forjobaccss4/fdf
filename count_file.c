/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:22:57 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/24 13:22:59 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		len_d_arr(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	free_double_array(char **need_free)
{
	int i;

	i = 0;
	if (!need_free)
		return ;
	while (need_free[i])
	{
		free(need_free[i]);
		i++;
	}
	free(need_free);
	need_free = NULL;
}

char	**coordinates_in_one_line(char *map_line)
{
	int		i;
	char	**splited;

	i = 0;
	splited = NULL;
	splited = ft_strsplit(map_line, ' ');
	return (splited);
}

int		len_of_map(char *map_line)
{
	char	**splited;
	int		len;

	splited = NULL;
	len = 0;
	splited = coordinates_in_one_line(map_line);
	len = len_d_arr(splited);
	free_double_array(splited);
	return (len);
}