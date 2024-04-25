/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   dot_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:40:21 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/08 19:41:11 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	covert_mid_lines(t_map **map, char ***tmp, int len, int *j)
{
	int	i;

	while (*map && (*map)->next)
	{
		(*tmp)[*j] = malloc(sizeof(char) * (len + 1));
		i = 0;
		while (i < len && ((*map)->line[i] != '\n' && (*map)->line[i] != '\0'))
		{
			if ((*map)->line[i] == ' ')
				(*tmp)[*j][i] = '.';
			else
				(*tmp)[*j][i] = (*map)->line[i];
			i++;
		}
		while (i < len)
		{
			(*tmp)[*j][i] = '.';
			i++;
		}
		(*tmp)[*j][i] = '\0';
		*map = (*map)->next;
		(*j)++;
	}
}

void	covert_last_line(t_map **map, char ***tmp, int len, int *j)
{
	int	i;

	i = 0;
	(*tmp)[*j] = malloc(sizeof(char) * (len + 1));
	while (i < len && ((*map)->line[i] != '\n' && (*map)->line[i] != '\0'))
	{
		if ((*map)->line[i] == ' ')
			(*tmp)[*j][i] = '.';
		else
			(*tmp)[*j][i] = (*map)->line[i];
		i++;
	}
	while (i < len)
	{
		(*tmp)[*j][i] = '.';
		i++;
	}
	(*tmp)[*j][i] = '\0';
}

int	check_dot(char **tmp, int j, int i, int rows)
{
	if (tmp[j][i] && tmp[j][i] == '.')
	{
		if (tmp[j][i + 1] && tmp[j][i + 1] == '0')
		{
			ft_putstr("MAPA ABIERTO");
			return (1);
		}
		if (j < (rows - 1))
		{
			if (tmp[j + 1] && tmp[j + 1][i] == '0')
			{
				ft_putstr("MAPA ABIERTO");
				return (1);
			}
		}
	}
	return (0);
}

int	check_zero(char **tmp, int j, int i, int rows)
{
	if (tmp[j][i] && tmp[j][i] == '0')
	{
		if (tmp[j][i + 1] && tmp[j][i + 1] == '.')
		{
			ft_putstr("MAPA ABIERTO");
			return (1);
		}
		if (j < (rows - 1))
		{
			if ((tmp[j + 1] && tmp[j + 1][i] == '.') || !tmp[j + 1])
			{
				ft_putstr("MAPA ABIERTO");
				return (1);
			}
		}
		if ((!tmp[j][i + 1] || (tmp[j][i + 1] && tmp[j][i + 1] == '\0')) || \
			j == (rows - 1))
		{
			ft_putstr("MAPA ABIERTO");
			return (1);
		}
	}
	return (0);
}

int	create_tmp_map(t_map *map, int len, int rows)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char *) * (rows));
	covert_mid_lines(&map, &tmp, len, &j);
	if (map)
		covert_last_line(&map, &tmp, len, &j);
	j = 0;
	while (tmp[j] && j < rows)
	{
		i = 0;
		while (tmp[j][i])
		{
			if (check_dot(tmp, j, i, rows))
				return (1);
			if (check_zero(tmp, j, i, rows))
				return (1);
			i++;
		}
		j++;
	}
	free(tmp);
	return (0);
}
