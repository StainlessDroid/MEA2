/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/03/02 19:58:09 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     error_exit(int flag)
{
    ft_putstr("Error\n");
    if (flag == 1)
        ft_putstr("Invalid map\n");
    else if (flag == 2)
        ft_putstr("Memory allocation failed\n");
    //call to free_mem functions
    return (1);
}

void    diy_pixel_put(t_img_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/* Here the 3D point (voxel) gets converted to it's 2D equivalent (pixel)
** and adjusted for isometric representation
*/

t_pixel voxtopix(t_voxel source)
{
    t_pixel dst;

    dst.x =450 + (source.x - source.y) * 12;
    dst.y =150 + (source.x + source.y) * 12 - (source.z * 6);
    if (source.z > 0)
        dst.color = 0xFF0000;
    else
        dst.color = source.color;
    return (dst);
}