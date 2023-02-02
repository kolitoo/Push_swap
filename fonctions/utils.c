/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:05:56 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 13:43:02 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_atoii2(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\f'
		|| str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v')
	{
		*i = *i + 1;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = *sign * -1;
		*i = *i + 1;
	}
}

int	ft_atoii(const char *str, t_list **lst)
{
	int					i;
	int					sign;
	unsigned int		nb;
	long long			temp;

	i = 0;
	sign = 1;
	nb = 0;
	ft_atoii2(str, &i, &sign);
	while (str[i] >= 48 && str[i] <= 57)
	{
		temp = nb;
		nb = nb * 10 + str[i] - 48;
		i++;
		if (nb < temp)
		{
			ft_lstclear(lst);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	return (sign * nb);
}

int	comp_indjmore(t_list *lst, int j)
{
	int	i;
	int	k;
	int	size;

	i = 1;
	k = 1;
	size = ft_lstsize(lst);
	while (lst != NULL)
	{
		if (lst->index <= j)
			k = i;
		i++;
		lst = lst->next;
	}
	k = size - k + 1;
	return (k);
}

int	ind_le_plus_grand(t_list *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index > i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}

int	ind_le_plus_petit(t_list *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index < i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}
