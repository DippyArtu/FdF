/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:36:00 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/07 18:15:44 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				isnbr(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == ',' && (str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			check++;
			i++;
		}
		else if ((str[i] >= 48 && str[i] <= 57) || (i == 0 && str[i] == 45))
			i++;
		else if (i > 1 && check && ((str[i] >= 65 && str[i] <= 70)
									|| str[i] == 120))
			i++;
		else
			return (-1);
	}
	return (0);
}

static int		count_width(char *file)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wordcounter(line);
	free(line);
	close(fd);
	return (width);
}

static int		count_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

static void		fill_matrix(int *z_line, char *line, t_map *map)
{
	char		**nums;
	int			i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		if (isnbr(nums[i]) == -1)
		{
			ft_putstr(ERROR_FILE);
			exit(0);
		}
		z_line[i] = ft_atoi(nums[i]);
		if (z_line[i] > map->z_max)
			map->z_max = z_line[i];
		if (z_line[i] < map->z_min)
			map->z_min = z_line[i];
		ft_strdel(&nums[i]);
		i++;
	}
	free(nums);
}

void			read_file(char *file, t_map *map, int *zoom)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->height = count_height(file);
	map->width = count_width(file);
	map->matrix = (int **)malloc(sizeof(int *) * (map->height + 1) * 10);
	fd = open(file, O_RDONLY);
	while (i <= map->height)
		map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1) * 10);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_wordcounter(line) != map->width)
			read_error();
		fill_matrix(map->matrix[i++], line, map);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	*zoom = min_val(((WIDTH_WIN / map->width) * 0.7),\
		((HEIGHT_WIN / map->height) * 0.7));
}
