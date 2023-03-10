/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:45:07 by mpascual          #+#    #+#             */
/*   Updated: 2023/03/12 18:15:59 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_free(char *line, char **aux)
{
	int	i;

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

int	read_map(t_map_tools *mtools)
/*
** Linux compatibility is broken by the malloc call
** I think it segafaults in linux because the **map is not initialized
*/

{
	char	*line;
	char	**aux;

	line = NULL;
	mtools->rows = 0;
	while (get_next_line(mtools->fd, &line))
	{
		mtools->columns = check_line(line, mtools->columns);
		if (mtools->columns < 0)
			return (read_free(line, NULL));
		aux = ft_split(line, ' ');
		mtools->map[mtools->rows] = malloc(sizeof(t_voxel) * mtools->columns);
		if (mtools->map[mtools->rows] == NULL)
			return (read_free(line, aux));
		store_map(mtools, aux);
		mtools->rows++;
	}
	if (mtools->rows == 0 || mtools->columns == 0)
		return (EXIT_FAILURE);
	read_free(line, aux);
	return (EXIT_SUCCESS);
}

static char	*check_point(char *str)
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

int	check_line(char *line, int columns)
{
	int	x;

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
