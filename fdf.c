/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:58:18 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/18 16:58:54 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    diy_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     keypress(int keycode, t_mlx_vars *vars)
{
    if (keycode == KEY_ESCAPE)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

int main()
{
    t_mlx_vars  vars;
    t_data      img;

    vars.mlx = mlx_init();
    vars.width = 600;
    vars.height = 600;
    vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Testing");
    img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
    mlx_loop(vars.mlx);
    return (EXIT_SUCCESS);
}