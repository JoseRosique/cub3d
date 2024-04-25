/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:37:21 by joslopez          #+#    #+#             */
/*   Updated: 2023/11/07 19:06:16 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	obtain_map(t_arg *arg, char *buffer)
{
	t_map	*tmp;

	tmp = ft_lstnew_map(map_without_spaces(buffer, ' ', 0, 0));
	if (!tmp)
		return (0);
	ft_lstadd_back_map(&(arg->map), tmp);
	return (0);
}

int	screen_size(t_arg *variables)
{
	variables->screen_w = 1000;
	variables->screen_h = 800;
	if (variables->screen_h <= 0 || variables->screen_w <= 0)
	{
		ft_putstr("Error\nWrong screen dimensions");
		return (1);
	}
	if (variables->screen_h >= 800)
		variables->screen_h = 800;
	if (variables->screen_w >= 1000)
		variables->screen_w = 1000;
	return (0);
}

int	check_doubles_floor_ceil(t_arg *variables, char *buffer)
{
	if (ft_strchr("FC", buffer[0]))
	{
		if (buffer[0] == 'F')
			variables->fcounter++;
		if (buffer[0] == 'C')
			variables->ccounter++;
		if (variables->fcounter > 1 || variables->ccounter > 1)
		{
			ft_putstr("Error\nProblems with floor or ceil");
			return (1);
		}
		if (check_floor_ceil(variables, buffer) != 0)
		{
			ft_putstr("Error\nProblems with floor or ceil");
			return (1);
		}
	}
	return (0);
}

int	check_identifier2(t_arg *variables, char *buffer)
{
	if (check_doubles_floor_ceil(variables, buffer) != 0)
		return (1);
	if (ft_isdigit(buffer[0]) || buffer[0] == ' ')
	{
		if (obtain_map(variables, buffer) != 0)
		{
			ft_putstr("Error\nProblems with map");
			return (1);
		}
	}
	if (!ft_isdigit(buffer[0]) && !ft_strchr("NSEWFC ", buffer[0]))
	{
		ft_putstr("Error\nUnknown argument in map");
		return (1);
	}
	return (0);
}

int	check_identifier(t_arg *variables, char *buffer)
{
	if (buffer[0] == '\n' || buffer[0] == '\0')
		return (0);
	if (ft_strchr("NSWE", buffer[0]))
	{
		if (check_orientation(variables, buffer) != 0)
			return (1);
	}
	if (check_identifier2(variables, buffer) != 0)
		return (1);
	if (screen_size(variables) != 0)
		return (1);
	return (0);
}
