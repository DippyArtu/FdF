/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:28:59 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 20:33:42 by jsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				point_color(int z, t_fdf *data)
{
	double		r;

	r = ratio(data->map->z_min, data->map->z_max, z);
	if (r < 0.1)
		return (PINK_0);
	if (r < 0.2)
		return (DARK_PURPLE_1);
	else if (r < 0.4)
		return (DARK_CERISE_2);
	else if (r < 0.6)
		return (DARK_RASBERRY_3);
	else if (r < 0.8)
		return (MODERATE_CRIMSON_4);
	else if (r < 0.9)
		return (MODERATE_AMARANTH_5);
	else
		return (TURQUOISE_6);
}

static int		gradient(int start, int end, double ratio)
{
	return ((1 - ratio) * start + ratio * end);
}

int				color(t_points point, t_points start, t_points end)
{
	int			r;
	int			g;
	int			b;
	double		rat;

	if (point.color == end.color)
		return (point.color);
	if (mod(start.x - end.x) > mod(start.y - end.y))
		rat = ratio(start.x, end.x, point.x);
	else
		rat = ratio(start.y, end.y, point.y);
	r = gradient((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, rat);
	g = gradient((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, rat);
	b = gradient(start.color & 0xFF, end.color & 0xFF, rat);
	return ((r << 16) | (g << 8) | b);
}
