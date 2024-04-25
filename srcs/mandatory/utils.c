/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:05:58 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/19 19:54:07 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*map_without_spaces(char *str, char c, int i, int j)
{
	int		len;
	char	*new_str;

	(void)c;
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (NULL);
	while (i < len)
	{
		if (str[i])
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

t_map	*ft_lstlast_map(t_map *lst)
{
	t_map	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
