/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:36:00 by tgarkbit          #+#    #+#             */
/*   Updated: 2020/08/09 11:36:01 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		g_left_clicked = 0;
		g_right_clicked = 0;
		fdf = NULL;
		fdf = initialize_fdf(fdf, av);
		mlx_hook(fdf->win_ptr, 2, 2, keyboard_control, fdf);
		mlx_hook(fdf->win_ptr, 6, 2, mouse_control, fdf);
		mlx_hook(fdf->win_ptr, 4, 2, mouse_press, fdf);
		mlx_hook(fdf->win_ptr, 5, 2, mouse_release, fdf);
		draw(fdf->map, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
	{
		ft_putstr("usage: ./fdf <map_name>");
	}
	return (0);
}

t_fdf		*initialize_fdf(t_fdf *fdf, char **av)
{
	fdf = malloc(sizeof(t_fdf));
	fdf->camera = malloc(sizeof(t_camera));
	fdf->map = malloc(sizeof(t_map));
	fdf->camera->posx = 300;
	fdf->camera->posy = 150;
	fdf->camera->zoom = 7;
	fdf->camera->a = 60;
	fdf->camera->b = 60;
	fdf->camera->c = 60;
	fdf->camera->iso = 0;
	fdf->camera->zoomb = 1;
	fdf->camera->move = 1;
	fdf->mlx_ptr = mlx_init();
	*(fdf->map) = get_map(av);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1500, 1500, "42 visualizer");
	return (fdf);
}

t_map		get_map(char **av)
{
	int		fd;
	char	*line;
	char	**grid;
	t_map	map_stat;

	map_stat = line_num(av);
	grid = (char **)malloc(sizeof(char *) * map_stat.height + 1);
	fd = open(av[1], O_RDONLY);
	map_stat.height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		grid[map_stat.height] = ft_strdup(line);
		ft_strdel(&line);
		map_stat.height++;
	}
	grid[map_stat.height] = NULL;
	map_stat = line_num(av);
	close(fd);
	return (char_to_arr(grid, map_stat));
}


t_map		line_num(char **av)
{
	t_map	map_stat;
	int		fd;
	char	*line;

	map_stat.height = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		map_stat.height++;
	}
	close(fd);
	return (map_stat);
}

t_map		char_to_arr(char **grid, t_map map_stat)
{
	int		**map;
	int		i;
	char	**str;
	int		j;

	i = 0;
	map = (int **)malloc(sizeof(int *) * (map_stat.height + 1));//малочим указатель на строки с циферками
	while (grid[i])
	{
		j = 0;
		map_stat.width = 0;
		str = ft_strsplit(grid[i], ' ');
		while (str[map_stat.width])
			map_stat.width++;
		map[i] = (int *)malloc(sizeof(int) * map_stat.width);//малочим указатель на строку с циферками
		while (str[j])
		{
			map[i][j] = ft_atoi(str[j]);
			ft_strdel(&str[j++]);
		}
		free(str);
		free(grid[i]);
		i++;
	}
	free(grid);
	return (f_obnulenie(map_stat, map, i));
}
