/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:15:15 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/01 14:05:32 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (*src != '\0')
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;
	int					len;

	tab = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len] != '\0')
			len++;
		tab[i].size = len;
		tab[i].str = av[i];
		tab[i].copy = ft_strcpy(av[i], len);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
