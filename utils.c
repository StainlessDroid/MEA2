/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/03/12 21:06:38 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_exit(int flag)
{
	ft_putstr("Error\n");
	if (flag == 1)
		ft_putstr("Invalid map\n");
	else if (flag == 2)
		ft_putstr("Memory allocation failed\n");
	return (1);
}

void	diy_pixel_put(t_img_data *data, int x, int y, int color)
/*
** RANDOM SEGFAULTS
*/
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_pixel	voxtopix(t_voxel source)
/*
** The 3D point (voxel) gets converted to it's 2D isometric representation
** (pixel) by rotating the map 45º and reducing the height by half
*/
{
	t_pixel	dst;

	dst.x = 1024/2 + (source.x - source.y) * 12;
	dst.y = 300 + ((source.x + source.y) * 12) / 2 - (source.z * 12);
	if (source.z > 0)
		dst.color = 0xFF0000;
	else
		dst.color = source.color;
	return (dst);
}
