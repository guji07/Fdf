//
// Created by Владимир on 11.08.2020.
//

#include "fdf.h"

void free_fdf(t_fdf *fdf)
{
	int 	i;

	free(fdf->camera);
	free(fdf->map);
	i = -1;
	while (++i)
	{
		if ((fdf->map->map)[i] != NULL)
			free(fdf->map->map[i]);
	}
	free(fdf->map->map);
	free(fdf->map);
	free(fdf);
}