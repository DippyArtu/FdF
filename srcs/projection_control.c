/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalome <jsalome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:34:21 by jsalome           #+#    #+#             */
/*   Updated: 2020/03/06 18:39:36 by jsalome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		projection_control(int key, t_fdf *data)
{
	if (key == 34)
	{
		data->pos->alpha = -0.523599;
		data->pos->beta = -0.523599;
		data->pos->gamma = 0.523599;
	}
	else if (key == 35)
	{
		data->pos->alpha = 0;
		data->pos->beta = 0;
		data->pos->gamma = 0;
	}
}
