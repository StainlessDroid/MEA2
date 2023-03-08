/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:10:56 by mpascual          #+#    #+#             */
/*   Updated: 2023/03/08 22:39:33 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Bresenham's line drawing algorithm 
**  two similar functions for low and high slope are needed
    
*/
int    draw_line_low(t_img_data *data, t_pixel a, t_pixel b)
{
    int dx, dy;
    int x, y;
    int dif;
    int yi;

    dx = b.x - a.x;
    dy = b.y -a.y;
    yi = 1;
    if (dy < 0)
    {
        dy = -dy;
        yi = -1;
    }
    dif = (2 * dy) - dx;
    y = a.y;
    x = a.x;
    while (x < b.x)
    {
        diy_pixel_put(data, x, y, b.color);
        if (dif > 0)
        {
            y += yi;
            dif = dif + 2 * (dy - dx);
        }
        else
            dif = dif + 2 * dy;
        x++;
    }
    return (0);
}

int    draw_line_high(t_img_data *data, t_pixel a, t_pixel b)
{
    int dx, dy;
    int x, y;
    int dif;
    int xi;

    dx = b.x - a.x;
    dy = b.y - a.y;
    xi = 1;
    if (dx < 0)
    {
        dx = -dx;
        xi = -1;
    }
    dif = (2 * dx) - dy;
    y = a.y;
    x = a.x;
    while (y < b.y)
    {
        diy_pixel_put(data, x, y, b.color);
        if (dif > 0)
        {
            x += xi;
            dif = dif + 2 * (dx - dy);
        }
        else
            dif = dif + 2 * dx;
        y++;
    }
    return (0);
}

void    draw_line(t_img_data *data, t_pixel a, t_pixel b)
{
    if (abs(b.y - a.y) < abs(b.x - a.x))
    {
        if (a.x > b.x)
            draw_line_low(data, b, a);
        else
            draw_line_low(data, a, b);
    }
    else
    {
        if (a.y > b.y)
            draw_line_high(data, b, a);
        else
            draw_line_high(data, a, b);
    }
}

void    draw_map(t_map_tools *mtools, t_img_data *data)
{
    int     y;
    int     x;
    t_pixel point_a;
    t_pixel point_b;

    y = 0;
    while(y < mtools->rows)
    {
        x = 0;
        while (x < mtools->columns)
        {
            point_a = voxtopix(mtools->map[y][x]);
            if (x < mtools->columns - 1)
            {
                point_b = voxtopix(mtools->map[y][x + 1]);
                draw_line(data, point_a, point_b);
            }
            if (y < mtools->rows - 1)
            {
                point_b = voxtopix(mtools->map[y + 1][x]);
                draw_line(data, point_a, point_b);
            }
            diy_pixel_put(data, point_a.x, point_a.y, point_a.color);
            x++;
        }
        y++;
    }
}