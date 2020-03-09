/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:29:10 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 20:32:45 by jsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				restart(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image(data->mlx_ptr, WIDTH_WIN, HEIGHT_WIN);
	data->data_addr = mlx_get_data_addr(data->image, &(data->bpp),
			&(data->size_line), &(data->endian));
	draw(data);
}

int					mouse_press(int key, int x, int y, void *p)
{
	t_fdf			*data;

	(void)x;
	(void)y;
	data = (t_fdf *)p;
	if (key == 4 || key == 5)
	{
		zoom_control(key, data);
		draw(data);
	}
	else if (key == 1)
		data->mouse->press = 1;
	return (0);
}

int					mouse_release(int key, int x, int y, void *p)
{
	t_fdf			*data;

	(void)x;
	(void)y;
	(void)key;
	data = (t_fdf *)p;
	data->mouse->press = 0;
	return (0);
}

int					mouse_move(int x, int y, void *p)
{
	t_fdf			*data;

	data = (t_fdf *)p;
	data->mouse->prev_x = data->mouse->x;
	data->mouse->prev_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->press)
	{
		data->pos->beta += (x - data->mouse->prev_x) * 0.002;
		data->pos->alpha += (y - data->mouse->prev_y) * 0.002;
		restart(data);
	}
	return (0);
}
