/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:07:16 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 12:10:57 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_in_b(t_list **pileb, t_list **pilea, int j, int i)
{
	if (ft_lstsize(*pileb) > 2)
	{
		if (comp_indjless((*pilea), j) <= comp_indjmore((*pilea), j)
			&& (*pilea)->index > j && ft_lstsize(*pilea) > 2
			&& (*pileb)->index <= j - i)
			rotate_rotate(pilea, pileb);
		else if ((*pileb)->index <= j - i)
			rotate(pileb, 'B', 0);
	}
}

void	choose_j(int size, int *j, int i, int *k)
{
	if (size == 500)
		*j = *j + 60;
	else
		*j = *j + 40;
	if (*j > size - i)
		*k = 1;
}

void	sort_to_b(t_list **pilea, t_list **pileb, int i, int j)
{
	int	k;
	int	size;

	k = 0;
	size = ft_lstsize(*pilea);
	if (size == 500)
	{
		j = 60;
		i = 30;
	}
	while (ft_lstsize(*pilea) != 3)
	{
		if (check_index_less(*pilea, j) == 0)
			choose_j(size, &j, i, &k);
		else if ((*pilea)->index <= j && (*pilea)->index < size - 2)
		{
			push(pilea, pileb, 'B');
			if (k == 0)
				sort_in_b(pileb, pilea, j, i);
		}
		else
			rotate_or_not_rotate(pilea, j);
	}
}

static void	sort_to_a2(t_list **pilea, t_list **pileb, int i)
{
	if (i == 0)
	{
		push(pileb, pilea, 'A');
		while (last_pile(*pilea) == (*pilea)->index - 1)
			reverse_rotate(pilea, 'A', 0);
	}
	if (i == 1)
	{
		if (check_pos_more(*pileb) <= ft_lstsize(*pileb) / 2)
			rotate(pileb, 'B', 0);
		else
			reverse_rotate(pileb, 'B', 0);
	}
}

void	sort_to_a(t_list **pilea, t_list **pileb)
{
	while (ft_lstsize(*pileb) != 0)
	{
		if ((*pileb)->index == ind_le_plus_grand(*pileb))
			sort_to_a2(pilea, pileb, 0);
		else if ((*pileb)->index > last_pile(*pilea))
		{
			push(pileb, pilea, 'A');
			rotate(pilea, 'A', 0);
		}
		else if (ind_le_plus_grand(*pilea) == last_pile(*pilea))
		{
			push(pileb, pilea, 'A');
			if ((*pilea)->index != (*pilea)->next->index - 1)
				rotate(pilea, 'A', 0);
		}
		else if (ft_lstsize(*pileb) == 2)
		{
			if ((*pileb)->next->index == ind_le_plus_grand(*pileb))
				swap(pileb, 'B', 0);
		}
		else
			sort_to_a2(pilea, pileb, 1);
	}
}
