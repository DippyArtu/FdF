/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:44 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/10 01:00:59 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_pixel(t_fdf *data, int x, int y, int color)
{
	int		*pixel;

	pixel = (int *)(data->data_addr);
	if (x > 0 && y > 0 && x < WIDTH_WIN && y < HEIGHT_WIN)
		pixel[x + (y * WIDTH_WIN)] = color;
}

void			fill_background(t_fdf *data)
{
	int		i;
	int		*background;

	i = 0;
	background = (int *)data->data_addr;
	while (i < WIDTH_WIN * HEIGHT_WIN)
	{
		background[i] = DEEP_NAVY;
		i++;
	}
	background[i] = '\0';
}

static void		step_calc(t_points p1, t_points p2, t_fdf *data)
{
	float		x_step;
	float		y_step;
	t_points	start;
	int			max;
	int			valid;

	position(&p1.x, &p1.y, &p1.z, data);
	position(&p2.x, &p2.y, &p2.z, data);
	start.x = p1.x;
	start.y = p1.y;
	start.z = p1.z;
	start.color = p1.color;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = max_val(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	valid = validate_pts(p1, p2);
	while (valid && ((int)(p1.x - p2.x) || (int)(p1.y - p2.y)))
	{
		put_pixel(data, p1.x, p1.y, color(p1, start, p2));
		p1.x += x_step;
		p1.y += y_step;
	}
}

void			draw(t_fdf *data)
{
	int		x;
	int		y;

	fill_background(data);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x < data->map->width - 1)
				step_calc(init_pts(x, y, data), init_pts(x + 1, y, data), data);
			if (y < data->map->height - 1)
				step_calc(init_pts(x, y, data), init_pts(x, y + 1, data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	print_menu(data);
}
