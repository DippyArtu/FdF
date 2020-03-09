/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:29:07 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 20:33:11 by jsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 15, TEXT_COLOR, "Controlls:");
	mlx_string_put(mlx, win, 15, y += 55, TEXT_COLOR, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Isometry: I");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Parralel: P");
	mlx_string_put(mlx, win, 15, y += 55, TEXT_COLOR, "Rotation:");
	mlx_string_put(mlx, win, 55, y += 25, TEXT_COLOR, "X-Axis - W/S");
	mlx_string_put(mlx, win, 55, y += 25, TEXT_COLOR, "Y-Axis - A/D");
	mlx_string_put(mlx, win, 55, y += 25, TEXT_COLOR, "Z-Axis - Q/E");
	mlx_string_put(mlx, win, 15, y += 55, TEXT_COLOR, "Mouse Scroll or Drag:");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Zoom or Rotation");
}
