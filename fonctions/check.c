/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:37:20 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 15:14:56 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_index(t_list **lst)
{
	t_list	*start;
	t_list	*temp;
	int		count;

	start = *lst;
	temp = *lst;
	count = 0;
	while (count < ft_lstsize(*lst))
	{
		while ((*lst)->index != 0 && (*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
			temp = (*lst);
		}
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
			if ((temp->content > (*lst)->content) && (*lst)->index == 0)
				temp = (*lst);
		}
		temp->index = ++count;
		(*lst) = start;
		temp = (*lst);
	}
}

void	reset_index(t_list **lst)
{
	t_list	*start;

	start = (*lst);
	while ((*lst)->next != NULL)
	{
		(*lst)->index = 0;
		(*lst) = (*lst)->next;
	}
	(*lst)->index = 0;
	(*lst) = start;
}

int	check_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[++j] != NULL)
	{
		if (str[j][i] == '+' || str[j][i] == '-')
		{
			if (str[j][i + 1] >= '0' && str[j][i + 1] <= '9')
				i++;
			else
				return (0);
		}
		while (str[j][i] != '\0')
		{
			if (str[j][i] < '0' || str[j][i] > '9')
				return (0);
			i++;
		}
		i = 0;
	}
	return (1);
}

int	check_double(t_list *stru)
{
	t_list	*temp;

	while (stru != NULL)
	{
		if (stru->content > 2147483647)
			return (0);
		if (stru->content < -2147483648)
			return (0);
		temp = stru->next;
		while (temp != NULL)
		{
			if (stru->content == temp->content)
				return (0);
			temp = temp->next;
		}
		stru = stru->next;
	}
	return (1);
}

int	global_check(t_list *lst, char **argv)
{
	if (check_number(argv) == 0)
		return (0);
	if (check_double(lst) == 0)
		return (0);
	return (1);
}
