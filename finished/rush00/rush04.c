/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jischung <jischung@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:33:42 by jischung          #+#    #+#             */
/*   Updated: 2023/07/23 17:09:11 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print(int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (h < y)
	{
		w = 0;
		while (w < x)
		{
			if (w == 0 && h == 0)
				ft_putchar('A');
			else if ((w == x - 1 && h == 0) || (w == 0 && h == y - 1))
				ft_putchar('C');
			else if (w == x - 1 && h == y - 1)
				ft_putchar('A');
			else if (w == 0 || w == x - 1 || h == 0 || h == y - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}	

void	rush(int x, int y)
{
	char	*error;

	error = "ERROR : x or y is out of range.\n";
	if (x <= 0 || y <= 0)
		write(1, error, 32);
	else
		print(x, y);
}
