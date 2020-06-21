/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:59 by jsalome           #+#    #+#             */
/*   Updated: 2020/06/21 18:42:58 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define WIDTH_WIN 1600
# define HEIGHT_WIN 900

# define TEXT_COLOR 0xcefabb
# define DEEP_NAVY 0x03021E

# define PINK_0 0xFF008B
# define DARK_PURPLE_1 0x240B36
# define DARK_CERISE_2 0x4B0D35
# define DARK_RASBERRY_3 0x730F34
# define MODERATE_CRIMSON_4 0x9B1133
# define MODERATE_AMARANTH_5 0xC31432
# define TURQUOISE_6 0x05F3A4

# define USAGE "Usage: ./fdf MAP_FILE.fdf \n"
# define ERROR "Error opening a file \n" USAGE
# define WRONG_FILE "Invalid map file given as an argument \n" USAGE
# define ERROR_FILE "Map given is not valid \nMap must contain only digits \n"
# define READ_ERROR "Error reading a map \n"

typedef struct	s_mouse
{
	int		press;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct	s_points
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_points;

typedef struct	s_map
{
	int		height;
	int		width;
	int		z_max;
	int		z_min;
	int		**matrix;
	int		color;
}				t_map;

typedef struct	s_position
{
	int		zoom;
	double	z_zoom;
	int		zoom_limit;
	int		shift_x;
	int		shift_y;
	double	alpha;
	double	beta;
	double	gamma;
}				t_pos;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
	t_pos	*pos;
	t_mouse	*mouse;
	int 	animation_c;
	int 	animation_dir;
}				t_fdf;

t_fdf			*init_fdf_sruct(void);
t_pos			*init_position(void);
t_points		init_pts(float x, float y, t_fdf *data);
t_map			*map_init(void);
void			read_file(char *file, t_map *map, int *zoom);
void			fill_background(t_fdf *data);
void			draw(t_fdf *data);
void			x_axis(float *y, int *z, double alpha);
void			y_axis(float *x, int *z, double beta);
void			z_axis(float *x, float *y, double gamma);
float			mod(float a);
float			max_val(float a, float b);
float			min_val(float a, float b);
double			ratio(int a, int b, int z);
int				validate_pts(t_points p1, t_points p2);
int				isnbr(char *str);
void			position(float *x, float *y, int *z, t_fdf *data);
void			projection_control(int key, t_fdf *data);
void			shift_control(int key, t_fdf *data);
void			zoom_control(int key, t_fdf *data);
void			z_zoom_control(int key, t_fdf *data);
void			angle_control(int key, t_fdf *data);
int				point_color(int z, t_fdf *data);
int				color(t_points point, t_points start, t_points end);
void			print_menu(t_fdf *data);
int				mouse_press(int key, int x, int y, void *p);
int				mouse_release(int key, int x, int y, void *p);
int				mouse_move(int x, int y, void *p);
void			read_error(void);
void			animation(t_fdf *fdf);

\\i
#endif
