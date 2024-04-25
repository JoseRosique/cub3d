/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:00:20 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/24 17:52:00 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*create_image(t_env *env, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(env->mlx_ptr, width, height);
	if (!img->img_ptr)
		return (NULL);
	img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size_line, &img->endian);
	if (!img->img_data)
		return (NULL);
	img->width = width;
	img->height = height;
	return (img);
}

int	start_movement(t_env *env)
{
	free_image(env, env->img);
	env->img = create_image(env, env->width, env->height);
	if (env->img == NULL)
	{
		ft_putstr("Error\nProblems with image.");
		return (1);
	}
	movement(env);
	display_screen(env, 0);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->img_ptr, 0, \
			0);
	return (0);
}

int	free_walls(t_env *env)
{
	free_texture(env, env->tex_s);
	free_texture(env, env->tex_n);
	free_texture(env, env->tex_w);
	free_texture(env, env->tex_e);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
	return (0);
}

int	events(t_env env)
{
	env.win_ptr = mlx_new_window(env.mlx_ptr, env.width, env.height,
			"Felix & Jose Cub3D");
	if (!env.win_ptr)
	{
		ft_putstr("Error\nProblems with MLX function.");
		return (1);
	}
	mlx_hook(env.win_ptr, 17, STRUCTURENOTIFYMASK, free_walls, &env);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, keypress, &env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, leave_key, &env);
	mlx_loop_hook(env.mlx_ptr, start_movement, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
