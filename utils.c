/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:44:04 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/19 17:28:46 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     error_message(void)
{
    ft_putstr("Error\n");
    return (EXIT_FAILURE);
}

void    diy_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/* Bresenham's line drawing algorithm */
void    draw_line(t_data *data, t_point *a, t_point *b)
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