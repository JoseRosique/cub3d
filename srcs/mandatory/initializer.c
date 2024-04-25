/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:06:16 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/21 11:21:46 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_orientation(t_env *env)
{
	if (env->orientation == 'N')
	{
		env->ray.diry = -0.99;
		env->ray.planex = -0.80;
	}
	if (env->orientation == 'S')
	{
		env->ray.diry = 0.99;
		env->ray.planex = 0.80;
	}
	if (env->orientation == 'E')
	{
		env->ray.dirx = 0.99;
		env->ray.planey = -0.80;
	}
	if (env->orientation == 'W')
	{
		env->ray.dirx = -0.99;
		env->ray.planey = 0.80;
	}
}

int	rgb_to_hex(t_rgb color)
{
	int	output;

	output = 256 * 256 * color.r + 256 * color.g + color.b;
	return (output);
}

void	start_colors_and_size(t_env *env, t_arg variables)
{
	env->width = variables.screen_w;
	env->height = variables.screen_h;
	env->floor = rgb_to_hex(variables.floor);
	env->ceil = rgb_to_hex(variables.ceil);
	env->arg = variables;
	start_orientation(env);
	env->mlx_ptr = mlx_init();
	env->player_x += 0.5;
	env->player_y += 0.5;
}

void	start_position(t_env *env, t_arg variables, int y, int x)
{
	t_map	*tmp;

	tmp = variables.map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x] != '\0')
		{
			if (ft_strchr("NSWE", tmp->line[x]))
			{
				env->orientation = tmp->line[x];
				env->player_x = x++;
				env->player_y = y++;
			}
			x++;
		}
		env->map_width = x;
		tmp = tmp->next;
		y++;
	}
	env->map_height = y - 1;
}

t_env	start_environment(t_arg variables)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	ft_bzero(&env.ray, sizeof(t_ray));
	start_position(&env, variables, 0, 0);
	env.ray.speed = 0.1;
	env.map = from_lst_to_tab(variables.map);
	if (!env.map)
	{
		ft_putstr("Error\nProblem with map creation");
		exit(0);
	}
	start_colors_and_size(&env, variables);
	start_orientation(&env);
	if (start_textures(&env) != 0)
		exit(0);
	env.ray.zbuffer = malloc(sizeof(double) * (env.width + 1));
	if (!env.ray.zbuffer)
	{
		ft_putstr("Error\nProblem with memory allocation");
		exit(0);
	}
	return (env);
}
