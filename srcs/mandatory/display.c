/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:34:45 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/19 19:58:21 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_height(t_env *env, char tex)
{
	int	height;

	height = 64;
	if (tex == 'E')
		height = env->tex_e->height;
	if (tex == 'N')
		height = env->tex_n->height;
	if (tex == 'W')
		height = env->tex_w->height;
	if (tex == 'S')
		height = env->tex_s->height;
	return (height);
}

int	get_texture_width(t_env *env, char tex)
{
	int	width;

	width = 64;
	if (tex == 'E')
		width = env->tex_e->width;
	if (tex == 'N')
		width = env->tex_n->width;
	if (tex == 'W')
		width = env->tex_w->width;
	if (tex == 'S')
		width = env->tex_s->width;
	return (width);
}

void	wall_texture(t_env *env, char tex)
{
	double	wallx;
	int		width;

	width = get_texture_width(env, tex);
	if (env->ray.wall == 0)
		wallx = env->ray.rposy - env->ray.dist * env->ray.rdiry;
	else
		wallx = env->ray.rposx - env->ray.dist * env->ray.rdirx;
	wallx -= (int)wallx;
	env->ray.tex_x = (int)(wallx * width);
	if (env->ray.wall == 0)
		env->ray.tex_x = width + env->ray.tex_x;
	else if (env->ray.wall == 1)
		env->ray.tex_x = width + env->ray.tex_x - 1;
	env->ray.step_tex = 1 * width / env->ray.rh;
	env->ray.tex_pos = (env->ray.wstart - env->height / 2 + env->ray.rh / 2)
		* env->ray.step_tex - 1;
}

int	display_screen(t_env *env, int x)
{
	char	tex;

	while (x < env->width)
	{
		init_ray(env, x);
		direction_ray(env);
		tex = hit_ray(env, 0);
		size_ray(env);
		wall_texture(env, tex);
		display_column(env, x++, tex, 0);
		env->ray.zbuffer[x] = env->ray.dist;
	}
	return (0);
}
