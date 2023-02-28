/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:10:52 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/28 12:45:00 by mpascual         ###   ########.fr       */
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

/*
** Transfer the current line of the map
*/

void    store_map(t_map_tools *m_tools, char **aux)
{
    int x;
    int color;

    x = 0;
    color = DEFAULT_COLOR;
    while (aux[x] && x <= m_tools->columns)
    {
        m_tools->map[m_tools->rows][x].x = x;
        m_tools->map[m_tools->rows][x].y = m_tools->rows;
        m_tools->map[m_tools->rows][x].z = ft_atoi(aux[x]);
        if (ft_strchr(aux[x], ','))
        {
            while (*aux[x] && *aux[x] != ',')
                aux[x]++;
            color = ft_atoi_base(aux[x], 16);
        }
        m_tools->map[m_tools->rows][x].color = color;
        x++;
    }
}