/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:54:15 by joslopez          #+#    #+#             */
/*   Updated: 2023/07/20 20:48:08 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((char)str[i] == '\n' | (char)str[i] == '\r' | (char)str[i] == '\t' | \
			(char)str[i] == '\f' | (char)str[i] == '\v' | (char)str[i] == ' ')
		i++;
	if ((char)str[i] == '+' && (char)str[i + 1] != '-')
		i++;
	if ((char)str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (((char)str[i] - '0') >= 0 && ('9' - (char)str[i]) >= 0)
	{
		nb = (nb * 10 + ((char)str[i] - '0'));
		i++;
	}
	return (nb * sign);
}
