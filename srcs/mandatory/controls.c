/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:45:21 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/12 20:20:28 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_env *env)
{
	if (!env->error)
	{
		ft_free_tex(env, env->tex_s);
		ft_free_tex(env, env->tex_n);
		ft_free_tex(env, env->tex_w);
		ft_free_tex(env, env->tex_e);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
	return (0);
}

int	keypress(int key, t_env *env)
{
	if (key == KEY_UP)
		env->move.up = 1;
	if (key == KEY_DOWN)
		env->move.down = 1;
	if (key == ROTATE_LEFT)
		env->move.left = 1;
	if (key == KEY_LEFT)
		env->move.move_left = 1;
	if (key == ROTATE_RIGHT)
		env->move.right = 1;
	if (key == KEY_RIGHT)
		env->move.move_right = 1;
	if (key == KEY_EXIT)
		ft_exit(env);
	return (0);
}

int	leave_key(int key, t_env *env)
{
	if (key == KEY_UP)
		env->move.up = 0;
	if (key == KEY_DOWN)
		env->move.down = 0;
	if (key == ROTATE_LEFT)
		env->move.left = 0;
	if (key == KEY_LEFT)
		env->move.move_left = 0;
	if (key == ROTATE_RIGHT)
		env->move.right = 0;
	if (key == KEY_RIGHT)
		env->move.move_right = 0;
	return (0);
}

void	free_texture(t_env *env, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}

void	free_image(t_env *env, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(env->mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
}
