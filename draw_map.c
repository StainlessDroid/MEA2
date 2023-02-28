/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:10:56 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/28 16:07:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Bresenham's line drawing algorithm */
void    draw_line(t_img_data *data, t_pixel *a, t_pixel *b)
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

void    draw_map(t_map_tools *mtools, t_img_data *data)
{
    int     y;
    int     x;
    t_pixel point;

    y = 0;
    x = 0;
    while(y < mtools->rows)
    {
        x = 0;
        while (x < mtools->columns)
        {
            point = voxtopix(mtools->map[y][x]);
            diy_pixel_put(data, point.x * 10 + 100, point.y * -10 + 100, point.color);
            x++;
        }
        y++;
    }
}