/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:58:49 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 15:00:57 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	create_check(t_list **lst, char **argv)
{
	*lst = ft_setlst(argv);
	if (global_check(*lst, argv) == 0)
	{
		write(2, "Error\n", 6);
		ft_lstclear(lst);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*pilea;
	t_list	*pileb;

	pileb = NULL;
	if (argc > 1)
	{
		if (create_check(&pilea, argv) == 0)
			return (1);
		put_index(&pilea);
		if (argc == 2 || argc == 3)
			resolve_2(&pilea);
		else if (argc == 4)
			resolve_3(&pilea);
		else if (argc == 6)
			resolve_5(&pilea, &pileb);
		else
			resolve(&pilea, &pileb);
		if (pileb != NULL)
			ft_lstclear(&pileb);
		ft_lstclear(&pilea);
	}
	return (0);
}
