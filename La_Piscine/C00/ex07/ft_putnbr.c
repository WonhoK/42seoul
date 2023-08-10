/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:27:06 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/20 19:19:15 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	arr[10];
	int		len;
	int		num;

	len = 0;
	if (nb < 0)
		write(1, "-", 1);
	if (nb == 0)
		write(1, "0", 1);
	while (nb != 0)
	{
		num = nb % 10;
		if (num < 0)
			num *= (-1);
		arr[len++] = '0' + num;
		nb /= 10;
	}
	while (len > 0)
	{
		write(1, &arr[--len], 1);
	}
}
