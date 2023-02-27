/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/25 19:02:14 by mpascual         ###   ########.fr       */
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

void    diy_pixel_put(t_data *data, int x, int y, int color)
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
    int     angle;

    angle = 45;
    dst.x = source.x + cos(angle) * source.z - cos(angle) * source.y;
    dst.y = -source.y * sin(angle) - source.z * sin(angle);
    dst.color = source.color;
    return (dst);
}

/* Bresenham's line drawing algorithm */
void    draw_line(t_data *data, t_pixel *a, t_pixel *b)
{
    int dx, dy;
    int p;
    int x, y;

    dx = b->x - a->x;
    dy = b->y - a->y;
    p = 2 * dy - dx;
    x = a->x;
    y = a->y;
    while(x < b->x)
    {
        if (p >= 0)
        {
            diy_pixel_put(data, x, y, 0xFFFFFF);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            diy_pixel_put(data, x, y, 0xFFFFFF);
            p = p + 2 * dy;
        }
        x++;
    }
}