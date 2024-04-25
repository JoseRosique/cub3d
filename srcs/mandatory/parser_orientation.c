/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:25:51 by joslopez          #+#    #+#             */
/*   Updated: 2023/08/30 19:03:48 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_orientation1(char *orientation, char *buffer, int i, t_arg *variables)
{
	if (!ft_strncmp("NO", orientation, 2))
	{
		if (ft_strlen(variables->no))
		{
			ft_putstr("Error\nWrong texture path");
			free(orientation);
			return (1);
		}
		variables->no = ft_strsub(buffer, i, ft_strlen(buffer) - i);
	}
	if (!ft_strncmp("SO", orientation, 2))
	{
		if (ft_strlen(variables->so))
		{
			ft_putstr("Error\nWrong texture path");
			free(orientation);
			return (1);
		}
		variables->so = ft_strsub(buffer, i, ft_strlen(buffer) - i);
	}
	if (check_orientation2(orientation, buffer, i, variables) != 0)
		return (1);
	return (0);
}

int	check_orientation(t_arg *variables, char *buffer)
{
	char	*orientation;
	int		i;

	if (ft_strlen(buffer) < 1)
	{
		ft_putstr("Error\nWrong texture path");
		return (1);
	}
	orientation = ft_strsub(buffer, 0, 2);
	i = 2;
	while (ft_strchr("\t\v\r\f ", buffer[i]))
	{
		i++;
	}
	if (check_orientation1(orientation, buffer, i, variables) != 0)
		return (1);
	return (0);
}

int	check_orientation2(char *orientation, char *buffer, int i, t_arg *variables)
{
	if (!ft_strncmp("WE", orientation, 2))
	{
		if (ft_strlen(variables->we))
		{
			ft_putstr("Error\nWrong texture path");
			free(orientation);
			return (1);
		}
		variables->we = ft_strsub(buffer, i, ft_strlen(buffer) - i);
	}
	if (!ft_strncmp("EA", orientation, 2))
	{
		if (ft_strlen(variables->ea))
		{
			ft_putstr("Error\nWrong texture path");
			free(orientation);
			return (1);
		}
		variables->ea = ft_strsub(buffer, i, ft_strlen(buffer) - i);
	}
	return (0);
}
