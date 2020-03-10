/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:50 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/10 20:03:21 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			file_validation(char *file)
{
	int		fd;
	char	test[2];

	fd = open(file, O_RDONLY);
	if (read(fd, test, 2) <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

	static int			deal_key(int key, t_fdf *data)
{
	if (key >= 123 && key <= 126)
		shift_control(key, data);
	else if (key == 24 || key == 27)
		zoom_control(key, data);
	else if (key == 47 || key == 43)
		z_zoom_control(key, data);
	else if ((key >= 12 && key <= 14) || (key >= 0 && key <= 2))
		angle_control(key, data);
	else if (key == 34 || key == 35)
		projection_control(key, data);
	else if (key == 18)
		animation(data);
	else if (key == 53)
		exit(0);
	draw(data);
	return (0);
}

int					main(int argv, char **argc)
{
	t_fdf	*data;

	if (argv != 2)
	{
		ft_putstr(ERROR);
		return (0);
	}
	if (!ft_strstr(argc[1], ".fdf") || !file_validation(argc[1]))
	{
		ft_putstr(WRONG_FILE);
		return (0);
	}
	data = init_fdf_sruct();
	read_file(argc[1], data->map, &data->pos->zoom);
	draw(data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_press, data);
	mlx_hook(data->win_ptr, 5, 0, mouse_release, data);
	mlx_hook(data->win_ptr, 6, 0, mouse_move, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
