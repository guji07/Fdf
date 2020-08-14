/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:35:34 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:35:40 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

t_point			*init_point(int x, int y, t_map *map_stat)
{
	t_point		*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = map_stat->map[y][x];
	point->h = map_stat->map[y][x];
	return (point);
}

void			draw_line(t_fdf *fdf, t_point s, t_point f)
{
	float		x_step;
	float		y_step;
	int			max;

	x_step = f.x - s.x;
	y_step = f.y - s.y;
	max = ft_abs(x_step) > ft_abs(y_step) ? ft_abs(x_step) : ft_abs(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(s.x - f.x) || (int)(s.y - f.y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, s.x, s.y,
				(int)f.h || (int)s.h ? 0xffff11 : 0xffffff);
		s.x += x_step;
		s.y += y_step;
	}
}

void			draw(t_map *map_stat, t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	*point_first;
	t_point	*point_second;

	y = 0;
	while (y < map_stat->height)
	{
		x = 0;
		while (x < map_stat->width)
		{
			if (x < map_stat->width - 1) {
				point_first = init_point(x, y, map_stat);
				point_second = init_point(x + 1, y, map_stat);
				draw_line(fdf, rotate(point_first, fdf), rotate(point_second, fdf));
				free(point_first);
				free(point_second);
			}
			if (y < map_stat->height - 1) {
				point_first = init_point(x, y, map_stat);
				point_second = init_point(x, y + 1, map_stat);
				draw_line(fdf, rotate(point_first, fdf), rotate(point_second, fdf));
				free(point_first);
				free(point_second);
			}
			x++;
		}
		y++;
	}
}
