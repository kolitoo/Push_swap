/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:36:39 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:06 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_pos(t_list *pilea, int k)
{
	int	i;

	i = 1;
	while (pilea->next != NULL)
	{
		if (pilea->index == k)
			return (i);
		i++;
		pilea = pilea->next;
	}
	if (pilea->index == k)
		return (i);
	return (0);
}

int	check_pos_less(t_list *pilea)
{
	t_list	*temp;
	t_list	*start;
	int		i;

	i = 1;
	temp = pilea;
	start = pilea;
	while (pilea->next != NULL)
	{
		if (temp->index < pilea->next->index)
			pilea = pilea->next;
		else
		{
			pilea = pilea->next;
			temp = pilea;
		}
	}
	pilea = start;
	while (pilea->index != temp->index)
	{
		pilea = pilea->next;
		i++;
	}
	return (i);
}

int	check_pos_more(t_list *pilea)
{
	t_list	*temp;
	t_list	*start;
	int		i;

	i = 1;
	temp = pilea;
	start = pilea;
	while (pilea->next != NULL)
	{
		if (temp->index > pilea->next->index)
			pilea = pilea->next;
		else
		{
			pilea = pilea->next;
			temp = pilea;
		}
	}
	pilea = start;
	while (pilea->index != temp->index)
	{
		pilea = pilea->next;
		i++;
	}
	return (i);
}

int	comp_indjless(t_list *lst, int j)
{
	int	i;

	i = 1;
	while (lst != NULL)
	{
		if (lst->index <= j)
			return (i);
		i++;
		lst = lst->next;
	}
	return (0);
}

int	last_pile(t_list *pile)
{
	int	i;

	while (pile->next != NULL)
		pile = pile->next;
	i = pile->index;
	return (i);
}
