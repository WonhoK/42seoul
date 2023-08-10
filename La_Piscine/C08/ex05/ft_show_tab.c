/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:53:15 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/01 13:23:51 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	putnbr(int n)
{
	char	num;

	num = n + '0';
	if (n / 10 == 0)
		write(1, &num, 1);
	else
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	len;

	while ((*par).str != 0)
	{
		len = (*par).size;
		write(1, (*par).str, len);
		write(1, "\n", 1);
		putnbr(len);
		write(1, "\n", 1);
		write(1, (*par).copy, len);
		write(1, "\n", 1);
		par++;
	}
}
