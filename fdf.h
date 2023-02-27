/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:02 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/27 21:24:29 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/* Set the corresponding keycode table for the current OS*/
# if defined __linux__
#  include "headers/mlx_input_linux.h"
# else
#  include "headers/mlx_input.h"
# endif
# include "headers/colors.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct s_mlx_vars
{
    void    *mlx;
    void    *win;
    int     img_width;
    int     img_height;
}               t_mlx_vars;


typedef struct s_voxel
{
    int x;
    int y;
    int z;
    int color;
}               t_voxel;

typedef struct s_pixel
{
    int x;
    int y;
    int color;
}               t_pixel;


typedef struct s_map_tools
{
    int fd;
    int columns;
    int rows;
    t_voxel **map;

}               t_map_tools;

/* from utils.c */
int     error_exit(int flag);
void    diy_pixel_put(t_data *data, int x, int y, int color);
void    draw_line(t_data *data, t_pixel *a, t_pixel *b);
/* from fdf.c */
int     keypress(int keycode, t_mlx_vars *vars);
/* from read_map.c*/
int     read_map(t_map_tools *m_tools);
int		check_line(char *line, int columns);
int     map_error(char *line, char **aux);
/* from store_map.c */
void    free_map(t_map_tools *m_tools);
void    store_map(t_map_tools *m_tools, char **aux);
/* from colors.C */
int     create_trgb(int t, int r, int g, int b);
int	    get_t(int trgb);
int     get_r(int trgb);
int     get_g(int trgb);
int     get_b(int trgb);

#endif