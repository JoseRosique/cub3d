/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:50:33 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/27 12:42:43 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	*create_texture(t_env *env, char *file, char *type)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	if (!tex)
		return (NULL);
	tex->tex_ptr = mlx_xpm_file_to_image(env->mlx_ptr, file, &tex->width,
			&tex->height);
	if (!tex->tex_ptr)
	{
		free(tex);
		return (NULL);
	}
	tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
			&tex->size_line, &tex->endian);
	if (!tex->tex_data)
	{
		free(tex->tex_ptr);
		free(tex);
		return (NULL);
	}
	tex->type = type;
	return (tex);
}

int	start_wall_sprites(t_env *env)
{
	env->tex_n = create_texture(env, env->arg.no, "NO");
	if (env->tex_n == NULL)
	{
		ft_putstr("Error\nTexture error in north.");
		return (1);
	}
	env->tex_s = create_texture(env, env->arg.so, "SO");
	if (env->tex_s == NULL)
	{
		ft_putstr("Error\nTexture error in south.");
		return (1);
	}
	env->tex_w = create_texture(env, env->arg.we, "WE");
	if (env->tex_w == NULL)
	{
		ft_putstr("Error\nTexture error in weast.");
		return (1);
	}
	env->tex_e = create_texture(env, env->arg.ea, "EA");
	if (env->tex_e == NULL)
	{
		ft_putstr("Error\nTexture error in east.");
		return (1);
	}
	return (0);
}

int	start_textures(t_env *env)
{
	if (start_wall_sprites(env) != 0)
		return (1);
	return (0);
}
