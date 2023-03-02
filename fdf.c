/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:58:18 by mpascual          #+#    #+#             */
/*   Updated: 2023/03/02 20:33:26 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     close_win(t_mlx_vars * vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    //free stuff just in case
    exit(EXIT_FAILURE);
    return (0);
}

int     keypress(int keycode, t_mlx_vars *vars)
{
    if (keycode == KEY_ESCAPE)
        close_win(vars);
    return (0);
}

int main(int argc, char **argv)
{
    t_mlx_vars  vars;
    t_img_data  data;;
    t_map_tools mtools;

    vars.mlx = mlx_init();
    if (argc != 2)
        exit(error_exit(1));
     mtools.fd = open(argv[1], O_RDONLY);
    if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) || !mtools.fd)
        exit(error_exit(1));
    if (read_map(&mtools))
        exit(error_exit(1));
    else
    {
        vars.img_width = 1024;
        vars.img_height = 768;
        vars.win = mlx_new_window(vars.mlx, vars.img_width, vars.img_height, "FDF");
        data.img = mlx_new_image(vars.mlx, vars.img_width, vars.img_height);
	    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
                                    &data.line_length, &data.endian);
        draw_map(&mtools, &data);
        mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
        mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
        mlx_hook(vars.win, 17, 0L, close_win, &vars);
        mlx_loop(vars.mlx);
    }
    return (EXIT_SUCCESS);
}