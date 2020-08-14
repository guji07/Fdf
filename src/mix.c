/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:36:00 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:36:01 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			free_fdf(t_fdf *fdf)
{
	int 	i;
	int		**map;

	free(fdf->camera);
	i = -1;
	map = fdf->map->map;
	while (map[i] != NULL)
		free(map[i]);
	free(fdf->map);
	free(map);
	free(fdf);
}

t_map			f_obnulenie(t_map map_stat, int **map, int i)
{
	map[i] = NULL;
	map_stat.map = map;
	return (map_stat);
}
