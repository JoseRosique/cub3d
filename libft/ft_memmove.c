/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:53:04 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 16:36:35 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ndest;
	unsigned char	*nsrc;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		ndest = (unsigned char *)dest;
		nsrc = (unsigned char *)src;
		while (n--)
			*ndest++ = *nsrc++;
	}
	else
	{
		ndest = (unsigned char *)dest + (n - 1);
		nsrc = (unsigned char *)src + (n - 1);
		while (n--)
			*ndest-- = *nsrc--;
	}
	return (dest);
}
