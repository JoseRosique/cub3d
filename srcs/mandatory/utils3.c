/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:57 by fde-fede          #+#    #+#             */
/*   Updated: 2024/01/08 19:41:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_wall_map(t_map *tmp, t_map *aux)
{
	size_t	len;
	size_t	next_len;

	while (tmp)
	{
		aux = aux->next;
		len = ft_strlen(tmp->line);
		len = check_last_wall(tmp->line, len);
		if (aux)
		{
			next_len = ft_strlen(aux->line);
			next_len = check_last_wall(aux->line, next_len);
		}
		if ((tmp->line[0] != '1' && tmp->line[0] != ' ') || (tmp->line[len \
			- 1] != '1') || (next_len >= len \
			&& aux && aux->line[len - 1] == '0'))
		{
			ft_putstr("Error\nMap not closed");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

size_t	check_last_wall(char *tmp, size_t len)
{
	int	i;

	i = 0;
	if (tmp[len - 1] == ' ')
	{
		i = 1;
		while (tmp[len - i] == ' ')
			i++;
	}
	if (i != 0)
		return (len - i + 1);
	else
		return (len);
}

int	check_characters(t_map *tmp, int i, t_map *prev)
{
	size_t	len;
	int		pos;

	len = ft_strlen(tmp->line);
	pos = check_last_wall(tmp->line, len);
	while (tmp->line[i])
	{
		if ((tmp->line[i] != '1' && tmp->line[i] != ' ') \
				|| (prev->line[i] == '0' \
				&& tmp->line[i] != '1') || \
				((prev->line[pos - 1] == '0') \
				&& (prev->line[pos] == '0')))
		{
			ft_putstr("Error\nLast Map Line not closed.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	extra_map_check(t_map *map)
{
	int		i;
	int		len;
	int		rows;
	t_map	*tmp;

	i = 0;
	rows = 1;
	len = 0;
	tmp = map;
	while (tmp->next)
	{
		i = 0;
		while (tmp->line[i])
			i++;
		if (i > len)
			len = i;
		tmp = tmp->next;
		rows++;
	}
	tmp = map;
	if (create_tmp_map(tmp, len, rows))
		return (1);
	return (0);
}
