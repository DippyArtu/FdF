/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:57 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 19:01:48 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mouse		*mouse_init(void)
{
	t_mouse		*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	mouse->press = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	return (mouse);
}

t_points	init_pts(float x, float y, t_fdf *data)
{
	t_points	point;

	point.x = x;
	point.y = y;
	point.z = data->map->matrix[(int)y][(int)x];
	point.color = point_color(point.z, data);
	return (point);
}

t_pos		*init_position(void)
{
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	pos->zoom = 1;
	pos->z_zoom = 0.1;
	pos->zoom_limit = 0;
	pos->alpha = -0.523599;
	pos->beta = -0.523599;
	pos->gamma = 0.523599;
	pos->shift_x = 1;
	pos->shift_y = 1;
	return (pos);
}

t_map		*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = 0;
	map->width = 0;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

t_fdf		*init_fdf_sruct(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->map = map_init();
	data->pos = init_position();
	data->mlx_ptr = mlx_init();
	data->mouse = mouse_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH_WIN, HEIGHT_WIN, "FDF");
	data->image = mlx_new_image(data->mlx_ptr, WIDTH_WIN, HEIGHT_WIN);
	data->data_addr = mlx_get_data_addr(data->image, &data->bpp, \
			&data->size_line, &data->endian);
	return (data);
}
