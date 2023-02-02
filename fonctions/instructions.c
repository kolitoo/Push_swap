/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:26:05 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 13:16:41 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list **lst, char c, int i)
{
	t_list	*ptr;
	int		temp;
	int		temp2;

	ptr = *lst;
	if (ptr != NULL && ptr->next != NULL)
	{
		temp = ptr->content;
		temp2 = ptr->index;
		ptr->content = ptr->next->content;
		ptr->index = ptr->next->index;
		ptr = ptr->next;
		ptr->content = temp;
		ptr->index = temp2;
		if (c == 'A' && i == 0)
			ft_printf("sa\n");
		else if (c == 'B' && i == 0)
			ft_printf("sb\n");
	}
}

void	push(t_list **pileA, t_list **pileB, char c)
{
	t_list	*temp;

	if (pileA != NULL)
	{
		if (pileB == NULL)
		{
			temp = (*pileA);
			(*pileB) = ft_lstnew((*pileA)->content);
			(*pileA) = (*pileA)->next;
			free (temp);
		}
		if (pileB != NULL)
		{
			temp = (*pileA)->next;
			(*pileA)->next = (*pileB);
			(*pileB) = (*pileA);
			(*pileA) = temp;
		}
		if (c == 'A')
			ft_printf("pa\n");
		else if (c == 'B')
			ft_printf("pb\n");
	}
}

void	rotate(t_list **lst, char c, int i)
{
	t_list	*ptr;
	t_list	*temp_first;
	t_list	*temp_last;

	if ((*lst) != NULL && ft_lstsize(*lst) > 2)
	{
		ptr = *lst;
		temp_first = ptr;
		ptr = ptr->next;
		temp_last = ptr;
		while (temp_last->next != NULL)
			temp_last = temp_last->next;
		temp_last->next = temp_first;
		temp_first->next = NULL;
		*lst = ptr;
		if (c == 'A' && i == 0)
			ft_printf("ra\n");
		else if (c == 'B' && i == 0)
			ft_printf("rb\n");
	}
}

void	reverse_rotate(t_list **lst, char c, int i)
{
	t_list	*ptr;
	t_list	*temp_first;
	t_list	*temp_last;

	if ((*lst) != NULL && ft_lstsize(*lst) > 2)
	{
		ptr = *lst;
		temp_first = ptr;
		ptr = ptr->next;
		temp_last = ptr;
		while (temp_last->next->next != NULL)
			temp_last = temp_last->next;
		temp_last->next->next = temp_first;
		*lst = temp_last->next;
		temp_last->next = NULL;
		if (c == 'A' && i == 0)
			ft_printf("rra\n");
		else if (c == 'B' && i == 0)
			ft_printf("rrb\n");
	}
}

void	resolve_2(t_list **pilea)
{
	if (ft_lstsize(*pilea) == 2)
	{
		if ((*pilea)->index > (*pilea)->next->index)
			swap(pilea, 'A', 0);
	}
}
