/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:08:28 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 17:39:58 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*t;

	if (!(s1 && s2))
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	t = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!t)
		return (NULL);
	ft_strlcpy(t, s1, s1_len + 1);
	ft_strlcat(t + (s1_len), s2, s2_len + 1);
	return (t);
}
