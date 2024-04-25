/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:46:56 by joslopez          #+#    #+#             */
/*   Updated: 2022/04/25 18:20:04 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = (-1) * n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = get_len(n);
	result = malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (0);
	result[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	while (n > 9)
	{
		count--;
		result[count] = (n % 10) + '0';
		n = n / 10;
	}
	result[count - 1] = n + '0';
	return (result);
}
