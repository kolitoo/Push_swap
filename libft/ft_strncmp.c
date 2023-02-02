/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:27:18 by abourdon          #+#    #+#             */
/*   Updated: 2022/11/21 11:21:48 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *) first;
	tab2 = (unsigned char *) second;
	i = 0;
	if (length == 0)
		return (0);
	while (tab1[i] && tab2[i] && tab1[i] == tab2[i] && i < length - 1)
	{
		i++;
	}
	return (tab1[i] - tab2[i]);
}
