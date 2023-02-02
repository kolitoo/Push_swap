/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:23:54 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:14 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_swap(t_list **pilea, t_list **pileb)
{
	swap(pilea, 'A', 1);
	swap(pileb, 'B', 1);
	ft_printf("ss\n");
}

void	rotate_rotate(t_list **pilea, t_list **pileb)
{
	rotate(pilea, 'A', 1);
	rotate(pileb, 'B', 1);
	ft_printf("rr\n");
}

void	reverse_reverse(t_list **pilea, t_list **pileb)
{
	reverse_rotate(pilea, 'A', 1);
	reverse_rotate(pileb, 'B', 1);
	ft_printf("rrr\n");
}

int	check_index_less(t_list *pilea, int j)
{
	while (pilea != NULL)
	{
		if (pilea->index <= j)
			return (1);
		pilea = pilea->next;
	}
	return (0);
}

int	check_index_max(t_list *pilea, int j)
{
	while (pilea != NULL)
	{
		if (pilea->index > j)
			return (1);
		pilea = pilea->next;
	}
	return (0);
}
