/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:10:52 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/27 17:02:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    free_map(t_map_tools *m_tools)
{
    int i;

    i = 0;
    while (i < m_tools->rows)
    {
        free(m_tools->map[i]);
        i++;
    }
    free(m_tools->map);
}

int     get_color(char *str)
{
    int         color;

    color = DEFAULT_COLOR;
    while (*str && *str != ',')
        str++;
    
    return (color);
}

/*
** Transfer the map from the readed text to t_voxel **map
** One line at a time
*/
void    store_map(t_map_tools *m_tools, char **aux)
{
    int i;

    i = 0;
    while (aux[i])
    {
        i++;
    }
}