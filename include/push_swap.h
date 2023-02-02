/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:59:39 by abourdon          #+#    #+#             */
/*   Updated: 2023/02/02 15:01:22 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	long long		content;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int number);
t_list	*ft_setlst(char **argv);
void	swap(t_list **lst, char c, int i);
void	ft_lstadd_back(t_list **start, t_list *temp);
void	ft_lstclear(t_list **lst);
void	print_lst(t_list *lst, t_list *lst2);
void	rotate(t_list **lst, char c, int i);
void	reverse_rotate(t_list **lst, char c, int i);
void	push(t_list **pileA, t_list **pileB, char c);
void	put_index(t_list **lst);
void	resolve_3(t_list **lst);
void	resolve_5(t_list **pilea, t_list	**pileb);
void	reset_index(t_list **lst);
void	swap_swap(t_list **pilea, t_list **pileb);
void	rotate_rotate(t_list **pilea, t_list **pileb);
void	reverse_reverse(t_list **pilea, t_list **pileb);
void	resolve(t_list **pilea, t_list **pileb);
void	sort_to_b(t_list **pilea, t_list **pileb, int i, int j);
void	sort_in_b(t_list **pileb, t_list **pilea, int j, int i);
void	sort_to_a(t_list **pilea, t_list **pileb);
void	rotate_or_not_rotate(t_list **pilea, int j);
void	resolve_2(t_list **pilea);
int		check_pos_less(t_list *pilea);
int		check_pos_more(t_list *pilea);
int		check_number(char **str);
int		check_double(t_list *stru);
int		global_check(t_list *lst, char **argv);
int		ft_lstsize(t_list *lst);
int		check_pos(t_list *pilea, int k);
int		check_index_less(t_list *pilea, int j);
int		check_index_max(t_list *pilea, int j);
int		comp_indjmore(t_list *lst, int j);
int		comp_indjless(t_list *lst, int j);
int		last_pile(t_list *pile);
int		find_j(int size);
int		ft_atoii(const char *str, t_list **lst);
int		ind_le_plus_grand(t_list *pile);
int		create_check(t_list **lst, char **argv);

#endif