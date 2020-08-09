/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:43:39 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:43:41 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			rotate_x(float *y, float *z, double a)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(a) + *z * sin(a);
	*z = -previous_y * sin(a) + *z * cos(a);
}

static void			rotate_y(float *x, float *z, double b)
{
	int		previous_x;

	previous_x = *x;
	*x = previous_x * cos(b) + *z * sin(b);
	*z = -previous_x * sin(b) + *z * cos(b);
}

void				iso(float *x, float *y, int z, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
	printf("%p", fdf->camera);
}

t_point				rotate(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->camera->zoom;
	p->y *= fdf->camera->zoom;
	p->z *= fdf->camera->zoom;
	if (fdf->camera->iso == 1)
		iso(&p->x, &p->y, p->z, fdf);
	else
	{
		rotate_x(&p->y, &p->z, fdf->camera->a);
		rotate_y(&p->x, &p->z, fdf->camera->b);
	}
	p->x += fdf->camera->posx;
	p->y += fdf->camera->posy;
	return (*p);
}
