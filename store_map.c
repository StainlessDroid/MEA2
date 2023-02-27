/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:10:52 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/27 18:53:40 by mpascual         ###   ########.fr       */
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
}

int     get_color(char *str)
{
    int color;
    int i;

    color = DEFAULT_COLOR;
    i = 0;
    while (*str && *str != ',')
        str++;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    color = ft_atoi_base(str, "0123456789ABCDEF");
    return (color);
}

/*
** Transfer the current line of the map
*/
void    store_map(t_map_tools *m_tools, char **aux)
{
    int     x;

    x = 0;
    while (aux[x] && x <= m_tools->columns)
    {
        m_tools->map[m_tools->rows][x].x = x;
        m_tools->map[m_tools->rows][x].y = m_tools->rows;
        m_tools->map[m_tools->rows][x].z = ft_atoi(aux[x]);
        m_tools->map[m_tools->rows][x].color = get_color(aux[x]);
        x++;
    }
}