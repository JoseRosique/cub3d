/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:11:17 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 12:36:53 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = malloc(n * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * n);
	return (p);
}
/*
int	main(void)
{
	printf("%s", ft_calloc(8, 8));
}
*/
