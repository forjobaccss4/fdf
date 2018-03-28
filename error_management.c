/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:24:21 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:24:22 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_d_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		free_structure(t_lst *new)
{
	int i;

	i = 0;
	if (new->int_arr != NULL)
		while (i < new->height)
		{
			free(new->int_arr[i]);
			i++;
		}
	free(new);
}

void		err_msg(char *str)
{
	if (str == NULL)
		return ;
	write(2, str, ft_strlen(str));
	exit(1);
}
