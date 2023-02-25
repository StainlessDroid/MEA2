/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:45:07 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/25 16:13:24 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int map_error(char *line, char **aux)
{
    int i;

    i = 0;
    free(line);
    if (aux)
    {
        while (aux[i])
        {
            free(aux[i]);
            i++;
        }
        free(aux);
    }
    return (EXIT_FAILURE);
}

int read_map(t_map_tools *m_tools)
{
    int i;
    char    *line;
    char    **aux;

    i = 0;
    line = NULL;
    m_tools->rows = 0;
    while (get_next_line(m_tools->fd, &line))
    {
        m_tools->columns = check_line(line, m_tools->columns);
        if (m_tools->columns < 0)
            return (map_error(line, NULL));
        aux = ft_split(line, ' ');
        if (aux == NULL)
            return (map_error(line, aux));
        m_tools->map[i] = malloc(sizeof(t_voxel) * m_tools->columns);
        //store_map(m_tools, aux);
        m_tools->rows++;
    }
    return (EXIT_SUCCESS);
}

static char		*check_point(char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	while (*str != ' ' && *str != ',' && *str)
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		++str;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' || *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str)
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			++str;
		}
	}
	return (str);
}

int		check_line(char *line, int columns)
{
	int		x;

	x = 0;
	while (*line)
	{
		while (*line == ' ')
			++line;
		line = check_point(line);
        if (line == NULL)
            return (-1);
        else
		    x++;
	}
    if (columns != 0 && x != columns)
        return (-1);
    else
        return (x);
}