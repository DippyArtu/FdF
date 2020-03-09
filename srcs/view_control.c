/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:36:12 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 20:30:45 by jsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		position(float *x, float *y, int *z, t_fdf *data)
{
	*x -= data->map->width / 2;
	*y -= data->map->height / 2;
	*x *= data->pos->zoom;
	*y *= data->pos->zoom;
	*z *= data->pos->zoom * data->pos->z_zoom;
	x_axis(y, z, data->pos->alpha);
	y_axis(x, z, data->pos->beta);
	z_axis(x, y, data->pos->gamma);
	*x += WIDTH_WIN / 2;
	*y += HEIGHT_WIN / 2;
	*x += data->pos->shift_x;
	*y += data->pos->shift_y;
}

void		shift_control(int key, t_fdf *data)
{
	if (key == 126)
		data->pos->shift_y -= 10;
	else if (key == 125)
		data->pos->shift_y += 10;
	else if (key == 123)
		data->pos->shift_x -= 10;
	else if (key == 124)
		data->pos->shift_x += 10;
}

void		zoom_control(int key, t_fdf *data)
{
	if (key == 24 || key == 5)
	{
		if (data->pos->zoom_limit <= 100)
		{
			data->pos->zoom += 1;
			data->pos->zoom_limit++;
		}
	}
	else if (key == 27 || key == 4)
	{
		if (data->pos->zoom_limit >= -40)
		{
			data->pos->zoom -= 1;
			data->pos->zoom_limit--;
		}
	}
}

void		z_zoom_control(int key, t_fdf *data)
{
	if (key == 47)
		data->pos->z_zoom += 0.1;
	else if (key == 43)
		data->pos->z_zoom -= 0.1;
	if (data->pos->z_zoom < -1.5)
		data->pos->z_zoom = -1.5;
	else if (data->pos->z_zoom > 1.5)
		data->pos->z_zoom = 1.5;
}

void		angle_control(int key, t_fdf *data)
{
	if (key == 13)
		data->pos->alpha += 0.07;
	else if (key == 1)
		data->pos->alpha -= 0.07;
	else if (key == 0)
		data->pos->beta += 0.07;
	else if (key == 2)
		data->pos->beta -= 0.07;
	else if (key == 12)
		data->pos->gamma += 0.07;
	else if (key == 14)
		data->pos->gamma -= 0.07;
}
