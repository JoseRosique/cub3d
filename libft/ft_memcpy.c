/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:24:17 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 16:29:15 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;
	size_t			i;

	if (!dest && !src)
		return (0);
	ndest = dest;
	nsrc = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*ndest++ = *nsrc++;
	return (dest);
}
