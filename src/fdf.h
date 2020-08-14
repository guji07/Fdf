/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:35:52 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:35:55 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78
# define MAIN_PAD_ESC		53
# define D_BUTTON			2
# define S_BUTTON			1
# define A_BUTTON			0
# define W_BUTTON			13
# define PLUS_BUTTON		24
# define MINUS_BUTTON		27
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>

int g_left_clicked;
int g_right_clicked;

typedef struct			s_map
{
	int					**map;
	int					width;
	int					height;
	int					x;
	int					y;
}						t_map;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
	int					h;
}						t_point;

typedef struct			s_camera
{
	float				zoom;
	int					zoomb;
	int					iso;
	int					move;
	int					posx;
	int					posy;
	double				a;
	double				b;
	double				c;
}						t_camera;

typedef	struct			s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_camera			*camera;
	t_map				*map;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_fdf;

int						ft_abs(int a);
t_point					*init_point(int x, int y, t_map *map_stat);
void					draw_line(t_fdf *fdf, t_point start, t_point finish);
void					draw(t_map *map_stat, t_fdf *fdf);
t_map					get_map(char **av);
t_fdf					*initialize_fdf(t_fdf *fdf, char **av);
int						mouse_control(int x, int y, void *fdf1);
t_point					rotate(t_point *p, t_fdf *fdf);
void					iso(float *x, float *y, int z, t_fdf *fdf);
t_map					f_obnulenie(t_map map_stat, int **map, int i);

/*
** keyboard control
*/

int						keyboard_control(int key, void *fdf1);
void					zoom_control(int key, t_fdf *fdf);
void					numpad_control(int key, t_fdf *fdf);
void					arrows_control(int key, t_fdf *fdf);
void					wasd_control(int key, t_fdf *fdf);

/*
** mouse control
*/

int						mouse_release(int button, int x, int y, void *fdf);
int						mouse_press(int button, int x, int y, void *fdf);

void 					free_fdf(t_fdf *fdf);
#endif
