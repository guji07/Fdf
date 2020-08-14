/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:36:04 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:36:07 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_control(int x, int y, void *fdf1)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	fdf->camera->zoomb = 0;
	fdf->camera->move = 0;
	x = 0;
	if (g_left_clicked == 1)
	{
		fdf->camera->a += 0.0001 * x;
		fdf->camera->b += 0.0001 * y;
	}
	if (g_right_clicked == 1)
	{
		fdf->camera->move = 1;
		fdf->camera->posx += 0.1 * x;
		fdf->camera->posy += 0.1 * y;
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf->map, fdf);
	return (0);
}

int			mouse_press(int button, int x, int y, void *fdf1)
{
	t_fdf	*fdf;

	if (button == 1)
		g_left_clicked = 1;
	if (button == 2)
		g_right_clicked = 1;
	x = 4;
	y = 3;
	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	return (0);
}

int			mouse_release(int button, int x, int y, void *fdf1)
{
	t_fdf	*fdf;

	if (button == 1)
		g_left_clicked = 0;
	if (button == 1)
		g_right_clicked = 0;
	x = 1;
	y = 2;
	fdf = (t_fdf *)fdf1;
	fdf->camera->iso = 0;
	return (0);
}
