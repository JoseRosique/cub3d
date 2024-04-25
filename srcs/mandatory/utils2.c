/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:26:33 by joslopez          #+#    #+#             */
/*   Updated: 2023/12/19 20:56:43 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_lstnew_map(void *content)
{
	t_map	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->line = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_map(t_map **alst, t_map *new)
{
	t_map	*tmp;

	tmp = *alst;
	if (tmp == NULL)
		*alst = new;
	else
		(ft_lstlast_map(*alst))->next = new;
}

void	ft_lstclear_map(t_map **lst)
{
	t_map	*tmp;
	t_map	*next;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

int	ft_lstsize_map(t_map *lst)
{
	t_map	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**from_lst_to_tab(t_map *lst)
{
	t_map	*tmp;
	int		i;
	char	**tab;

	tmp = lst;
	tab = malloc(sizeof(char *) * (ft_lstsize_map(lst) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_lstsize_map(lst))
	{
		tab[i] = ft_strdup(tmp->line);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
