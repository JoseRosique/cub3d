/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:55:18 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/24 22:01:31 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_pixel(t_img *img, unsigned int color, int p_x, int p_y)
{
	if (p_y >= img->height || p_x >= img->width || p_x < 0 || p_y < 0 || ((p_y
				* img->width + p_x) > (img->width * img->height - 1)))
	{
		ft_putstr("Error\nProblems with pixels.");
		return (1);
	}
	img->img_data[p_y * img->width + p_x] = color;
	return (0);
}

void	pixel_texture(t_tex *tex, t_env *env)
{
	if (tex->width * env->ray.tex_y + env->ray.tex_x < (tex->width * \
		tex->height))
		env->color = tex->tex_data[tex->width * env->ray.tex_y + \
		env->ray.tex_x];
}

char	*get_output_walls(t_env *env)
{
	if (env->ray.stepx < 0 && env->ray.rmapx < (int)env->ray.rposx
		&& env->ray.wall == 0)
	{
		pixel_texture(env->tex_e, env);
		return (env->arg.ea);
	}
	if (env->ray.stepx > 0 && env->ray.rmapx > (int)env->ray.rposx
		&& env->ray.wall == 0)
	{
		pixel_texture(env->tex_w, env);
		return (env->arg.we);
	}
	if (env->ray.stepy < 0 && env->ray.rmapy < (int)env->ray.rposy && \
		env->ray.wall - 0)
	{
		pixel_texture(env->tex_n, env);
		return (env->arg.no);
	}
	if (env->ray.stepy > 0 && env->ray.rmapy > (int)env->ray.rposy
		&& env->ray.wall == 1)
		pixel_texture(env->tex_s, env);
	return (env->arg.so);
}

char	*pixel_color(t_env *env)
{
	char	*output;

	output = NULL;
	if (!env->ray.door)
	{
		output = get_output_walls(env);
	}
	if (env->ray.door)
	{
		pixel_texture(env->tex_door, env);
		output = env->arg.door;
	}
	return (output);
}

char	*display_column(t_env *env, int x, char tex, int y)
{
	char	*tex_path;
	int		height;

	if (tex == 'E')
		height = env->tex_e->height;
	if (tex == 'N')
		height = env->tex_n->height;
	if (tex == 'W')
		height = env->tex_w->height;
	if (tex == 'S')
		height = env->tex_s->height;
	while (y < env->ray.wstart)
		put_pixel(env->img, env->ceil, x, y++);
	while (y >= env->ray.wstart && y <= env->ray.wend)
	{
		env->ray.tex_y = (int)env->ray.tex_pos & (height - 1);
		env->ray.tex_pos += env->ray.step_tex;
		tex_path = pixel_color(env);
		put_pixel(env->img, env->color, x, y);
		y++;
	}
	while (y < env->height)
		put_pixel(env->img, env->floor, x, y++);
	return (tex_path);
}
