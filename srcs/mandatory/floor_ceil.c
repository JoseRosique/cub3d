/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:04:55 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/21 11:31:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_after_rgb(char *buffer, int i)
{
	while (buffer[i])
	{
		if (!ft_isdigit(buffer[i]) && buffer[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_floor_ceil_2(t_arg *arg, char *buffer, int *i)
{
	int	tmp;

	tmp = *i;
	while (ft_isdigit(buffer[*i]))
		(*i)++;
	if (tmp == *i)
		return (1);
	while (!ft_isdigit(buffer[*i]) && buffer[*i] != '-')
	{
		if (ft_strchr("FC, ", buffer[*i]))
			(*i)++;
		else
			return (1);
	}
	if (ft_atoi(buffer + *i) > 255 || ft_atoi(buffer + *i) < 0 || \
		check_after_rgb(buffer, *i))
		return (1);
	if (buffer[0] == 'F')
		arg->floor.b = ft_atoi(buffer + *i);
	else
		arg->ceil.b = ft_atoi(buffer + *i);
	return (0);
}

int	aux_check_floor_ceil(t_arg *variables, char *buffer, int *i)
{
	int	tmp;

	if (buffer[0] == 'F')
		variables->floor.r = ft_atoi(buffer + *i);
	else
		variables->ceil.r = ft_atoi(buffer + *i);
	tmp = *i;
	while (ft_isdigit(buffer[*i]))
		(*i)++;
	if (tmp == *i)
		return (1);
	while (!ft_isdigit(buffer[*i]) && buffer[*i] != '-')
	{
		if (ft_strchr("FC, ", buffer[*i]))
			(*i)++;
		else
			return (1);
	}
	if (ft_atoi(buffer + *i) > 255 || ft_atoi(buffer + *i) < 0)
		return (1);
	if (buffer[0] == 'F')
		variables->floor.g = ft_atoi(buffer + *i);
	else
		variables->ceil.g = ft_atoi(buffer + *i);
	return (0);
}

int	check_floor_ceil(t_arg *variables, char *buffer)
{
	int	i;

	i = 0;
	while (!ft_isdigit(buffer[i]) && buffer[i] != '-')
	{
		if (ft_strchr("FC, ", buffer[i]))
			i++;
		else
			return (1);
	}
	if (ft_atoi(buffer + i) > 255 || ft_atoi(buffer + i) < 0)
		return (1);
	if (aux_check_floor_ceil(variables, buffer, &i) != 0)
		return (1);
	if (check_floor_ceil_2(variables, buffer, &i) != 0)
		return (1);
	return (0);
}
