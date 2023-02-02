/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:30:51 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 12:11:04 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	resolve_3(t_list **lst)
{
	if ((*lst)->index == 1 && (*lst)->next->index == 3
		&& (*lst)->next->next->index == 2)
	{
		reverse_rotate(lst, 'A', 0);
		swap(lst, 'A', 0);
	}
	else if ((*lst)->index == 2 && (*lst)->next->index == 3
		&& (*lst)->next->next->index == 1)
		reverse_rotate(lst, 'A', 0);
	else if ((*lst)->index == 2 && (*lst)->next->index == 1
		&& (*lst)->next->next->index == 3)
		swap(lst, 'A', 0);
	else if ((*lst)->index == 3 && (*lst)->next->index == 1
		&& (*lst)->next->next->index == 2)
		rotate(lst, 'A', 0);
	else if ((*lst)->index == 3 && (*lst)->next->index == 2
		&& (*lst)->next->next->index == 1)
	{
		swap(lst, 'A', 0);
		reverse_rotate(lst, 'A', 0);
	}
}

void	resolve_5(t_list **pilea, t_list	**pileb)
{
	while ((*pilea)->index != 1)
	{
		if ((*pilea)->next->index == 1)
			rotate(pilea, 'A', 0);
		else
			reverse_rotate(pilea, 'A', 0);
	}
	push(pilea, pileb, 'B');
	while ((*pilea)->index != 2)
	{
		if ((*pilea)->next->index == 2)
			rotate(pilea, 'A', 0);
		else
			reverse_rotate(pilea, 'A', 0);
	}
	push(pilea, pileb, 'B');
	reset_index(pilea);
	put_index(pilea);
	resolve_3(pilea);
	if ((*pileb)->index != 2)
		swap(pileb, 'B', 0);
	push(pileb, pilea, 'A');
	push(pileb, pilea, 'A');
	reset_index(pilea);
	put_index(pilea);
}

void	rotate_or_not_rotate(t_list **pilea, int j)
{
	if (comp_indjless((*pilea), j) <= comp_indjmore((*pilea), j))
		rotate(pilea, 'A', 0);
	else
		reverse_rotate(pilea, 'A', 0);
}

void	put_index_max(t_list **pilea, t_list **pileb)
{
	int	size;

	size = ft_lstsize(*pileb);
	(*pilea)->index = size + 1;
	(*pilea)->next->index = size + 2;
	(*pilea)->next->next->index = size + 3;
}

void	resolve(t_list **pilea, t_list **pileb)
{
	int	j;
	int	i;

	j = 40;
	i = 20;
	sort_to_b(pilea, pileb, i, j);
	reset_index(pilea);
	put_index(pilea);
	resolve_3(pilea);
	put_index_max(pilea, pileb);
	sort_to_a(pilea, pileb);
}
