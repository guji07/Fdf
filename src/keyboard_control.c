/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:36:15 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:36:17 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				keyboard_control(int key, void *fdf1)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	fdf->camera->zoomb = 0;
	fdf->camera->move = 0;
	zoom_control(key, fdf);
	numpad_control(key, fdf);
	arrows_control(key, fdf);
	wasd_control(key, fdf);
	if (key == MAIN_PAD_ESC)
	{
		(void)fdf;
		//free_fdf(fdf);
		exit(0);
	}
	if (key == NUM_PAD_0)
	{
		fdf->camera->iso = 1;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf->map, fdf);
	return (0);
}

void			zoom_control(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == PLUS_BUTTON)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom += 2;
	}
	if (key == NUM_PAD_MINUS || key == MINUS_BUTTON)
	{
		fdf->camera->zoomb = 1;
		fdf->camera->zoom -= 2;
	}
}

void			numpad_control(int key, t_fdf *fdf)
{
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
}

void			arrows_control(int key, t_fdf *fdf)
{
	if (key == ARROW_RIGHT)
	{
		fdf->camera->b += 0.15;
	}
	if (key == ARROW_DOWN)
	{
		fdf->camera->a += 0.15;
	}
	if (key == ARROW_LEFT)
	{
		fdf->camera->b -= 0.15;
	}
	if (key == ARROW_UP)
	{
		fdf->camera->a -= 0.15;
	}
}

void			wasd_control(int key, t_fdf *fdf)
{
	if (key == D_BUTTON)
	{
		fdf->camera->posx += 30;
	}
	if (key == A_BUTTON)
	{
		fdf->camera->posx -= 30;
	}
	if (key == W_BUTTON)
	{
		fdf->camera->posy -= 30;
	}
	if (key == S_BUTTON)
	{
		fdf->camera->posy += 30;
	}
}
