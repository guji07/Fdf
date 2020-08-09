//
// Created by Tuvok Garkbit on 8/9/20.
//

#include "fdf.h"

int			mouse_control(int key, void *fdf1)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	fdf->camera->zoomb = 0;
	fdf->camera->move = 0;
	if (key == 4)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom += 0.8;
	}
	if (key == 5)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom -= 0.8;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf->map, fdf);
	return (0);
}