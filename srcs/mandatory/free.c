/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:05:18 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/19 13:48:53 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tex(t_env *env, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(env->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}

void	ft_free_img(t_env *env, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(env->mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
}
