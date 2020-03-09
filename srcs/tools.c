/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:36:03 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/06 20:49:40 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float			mod(float a)
{
	return ((a < 0) ? a * -1 : a);
}

float			max_val(float a, float b)
{
	return ((a > b) ? a : b);
}

float			min_val(float a, float b)
{
	return ((a > b) ? b : a);
}

double			ratio(int a, int b, int z)
{
	double		r;
	double		dist;

	r = z - a;
	dist = b - a;
	return ((dist == 0) ? 1.0 : (r / dist));
}

int				validate_pts(t_points p1, t_points p2)
{
	if (((max_val(p1.x, p2.x) > 0) && (min_val(p1.x, p2.x)
	< WIDTH_WIN)) && ((max_val(p1.y, p2.y) > 0) && (min_val(p1.y, p2.y)
	< HEIGHT_WIN)))
		return (1);
	return (0);
}
