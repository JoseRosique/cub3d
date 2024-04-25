/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:00:21 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 17:21:22 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;

	if (*s2 == '\0')
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	s1_len = ft_strlen(s1);
	if (s1_len < s2_len || len < s2_len)
		return (0);
	if (s1_len > len)
	{
		size = len;
	}
	else
	{
		size = s1_len;
	}
	while (size-- >= s2_len)
	{
		if (ft_memcmp(s1, s2, s2_len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
