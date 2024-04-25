/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:13:11 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/19 19:58:00 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(t_env *env, int advance)
{
	double	dir;
	double	plane;

	dir = env->ray.dirx;
	plane = env->ray.planex;
	env->ray.dirx = env->ray.dirx * cos(advance * 0.1) - env->ray.diry
		* sin(advance * 0.1);
	env->ray.diry = dir * sin(advance * 0.1) + env->ray.diry * cos(advance
			* 0.1);
	env->ray.planex = env->ray.planex * cos(advance * 0.1) - env->ray.planey
		* sin(advance * 0.1);
	env->ray.planey = plane * sin(advance * 0.1) + env->ray.planey * cos(advance
			* 0.1);
}

void	up_down(t_env *env)
{
	if (env->move.up == 1)
	{
		if (ft_strchr("0SWEN", \
			env->map[(int)(env->player_y)][(int)(env->player_x \
				+ env->ray.dirx * env->ray.speed)]))
			env->player_x += env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWEN", env->map[(int)(env->player_y + env->ray.diry
					* env->ray.speed)][(int)(env->player_x)]))
			env->player_y += env->ray.diry * env->ray.speed;
	}
	if (env->move.down == 1)
	{
		if (ft_strchr("0SWEN", \
			env->map[(int)(env->player_y)][(int)(env->player_x \
				- env->ray.dirx * env->ray.speed)]))
			env->player_x -= env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWEN", env->map[(int)(env->player_y - env->ray.diry
					* env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= env->ray.diry * env->ray.speed;
	}
}

void	left_right(t_env *env)
{
	if (env->move.move_left == 1)
	{
		if (ft_strchr("0SWEN", env->map[(int)(env->player_y - env->ray.dirx
					* env->ray.speed)][(int)(env->player_x)]))
			env->player_y += -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWEN", \
			env->map[(int)(env->player_y)][(int)(env->player_x \
				+ env->ray.diry * env->ray.speed)]))
			env->player_x += env->ray.diry * env->ray.speed;
	}
	if (env->move.move_right == 1)
	{
		if (ft_strchr("0SWEN", env->map[(int)(env->player_y + env->ray.dirx
					* env->ray.speed)][(int)(env->player_x)]))
			env->player_y -= -env->ray.dirx * env->ray.speed;
		if (ft_strchr("0SWEN", \
			env->map[(int)(env->player_y)][(int)(env->player_x \
				- env->ray.diry * env->ray.speed)]))
			env->player_x -= env->ray.diry * env->ray.speed;
	}
}

void	movement(t_env *env)
{
	if (env->move.up == 1 || env->move.down == 1)
		up_down(env);
	if (env->move.move_left == 1 || env->move.move_right == 1)
		left_right(env);
	if (env->move.left == 1)
		ft_rotate(env, -1);
	if (env->move.right == 1)
		ft_rotate(env, 1);
}
