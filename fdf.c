/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:58:18 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/25 14:53:52 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     keypress(int keycode, t_mlx_vars *vars)
{
    if (keycode == KEY_ESCAPE)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_mlx_vars  vars;
    t_data      img;
    t_map_tools m_tools;

    vars.mlx = mlx_init();
    if (argc != 2)
        exit(error_exit(1));
     m_tools.fd = open(argv[1], O_RDONLY);
    if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) || !m_tools.fd)
        exit(error_exit(1));
    if (read_map(&m_tools))
        exit(error_exit(1));
    else
    {
        vars.img_width = 800;
        vars.img_height = 600;
        vars.win = mlx_new_window(vars.mlx, vars.img_width, vars.img_height, "FDF");
        img.img = mlx_new_image(vars.mlx, vars.img_width, vars.img_height);
	    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	    							&img.endian);
        mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
        mlx_hook(vars.win, 2, 1L<<0, keypress, &vars);
        mlx_loop(vars.mlx);
    }
    return (EXIT_SUCCESS);
}