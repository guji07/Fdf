//
// Created by Tuvok Garkbit on 8/9/20.
//

#include "fdf.h"

int			keyboard_control(int key, void *fdf1)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	fdf->camera->zoomb = 0;
	fdf->camera->move = 0;
	if (key == MAIN_PAD_ESC)
	{
		(void)fdf;
		exit(0);
	}
	if (key == NUM_PAD_6)
	{
		fdf->camera->move = 1;
		fdf->camera->posx += 20;
	}
	if (key == NUM_PAD_8)
	{
		fdf->camera->move = 1;
		fdf->camera->posy -= 10;
	}
	if (key == NUM_PAD_4)
	{
		fdf->camera->move = 1;
		fdf->camera->posx -= 20;
	}
	if (key == NUM_PAD_2)
	{
		fdf->camera->move = 1;
		fdf->camera->posy += 10;
	}
	if (key == NUM_PAD_PLUS || key == PLUS)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom += 0.8;
	}
	if (key == NUM_PAD_MINUS || key == MINUS)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom -= 0.8;
	}
	if (key == ARROW_RIGHT)
	{
		fdf->camera->b += 0.05;
	}
	if (key == ARROW_DOWN)
	{
		fdf->camera->a += 0.05;
	}
	if (key == ARROW_LEFT)
	{
		fdf->camera->b -= 0.05;
	}
	if (key == ARROW_UP)
	{
		fdf->camera->a -= 0.05;
	}
	if (key == NUM_PAD_0)
	{
		fdf->camera->iso = 1;
	}
	if (key == D_BUTTON)
	{
		fdf->camera->posx += 10;
	}
	if (key == A_BUTTON)
	{
		fdf->camera->posx -= 10;
	}
	if (key == W_BUTTON)
	{
		fdf->camera->posy -= 10;
	}
	if (key == S_BUTTON)
	{
		fdf->camera->posy += 10;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf->map, fdf);
	return (0);
}