/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:37:58 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 13:43:09 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int number)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = number;
	lst->index = 0;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **start, t_list *temp)
{
	t_list	*ptr;

	ptr = *start;
	if (start != NULL)
	{
		if (*start != NULL)
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = temp;
		}
		else
			*start = temp;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (lst != NULL)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			if (lst != NULL)
				free(*lst);
			(*lst) = ptr;
		}
	}
}

t_list	*ft_setlst(char **argv)
{
	t_list	*start;
	t_list	*temp;
	int		j;

	j = 1;
	start = ft_lstnew(ft_atoii(argv[j], &start));
	if (!start)
	{
		ft_lstclear(&start);
		exit(EXIT_FAILURE);
	}
	j++;
	while (argv[j] != NULL)
	{
		temp = ft_lstnew(ft_atoii(argv[j], &start));
		if (!temp)
		{
			ft_lstclear(&temp);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&start, temp);
		j++;
	}
	return (start);
}
