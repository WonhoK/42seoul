/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:16:47 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/03 20:28:11 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	long	num;
	char	c;

	num = (long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	c = num + '0';
	if (n / 10 == 0)
		write(1, &c, 1);
	else
	{
		putnbr(num / 10);
		putnbr(num % 10);
	}
}
