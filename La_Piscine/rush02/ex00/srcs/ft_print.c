/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:44:52 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/06 15:00:14 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_dict.h"

long long	char_to_nbr(char *num)
{
	long long	temp;

	temp = 0;
	while (*num != '\0')
	{
		temp = temp * 10 + *num - '0';
		num++;
	}
	return (temp);
}

void	print_value(long long nbr, t_dict *dict)
{
	char	temp[11];

	ft_strcmp(temp, int_to_char(temp, nbr)),
	ft_putstr(get_value(temp, dict));
}

void	print_three(long long nbr, t_dict *dict)
{
	char	temp[11];
	char	*res;

	if (nbr / 100 != 0)
	{
		print_value(nbr / 100, dict);
		write(1, " ", 1);
		print_value(100, dict);
		nbr %= 100;
		if (nbr != 0)
			write(1, " ", 1);
	}
	if (nbr != 0)
	{
		res = get_value(int_to_char(temp, nbr), dict);
		if (res != 0)
			ft_putstr(res);
		else
		{
			print_value((nbr / 10) * 10, dict);
			write(1, " ", 1);
			print_value(nbr % 10, dict);
		}
	}
}

void	print_whole(char *num, t_dict *dict)
{
	long long	nbr;
	long long	div;

	nbr = char_to_nbr(num);
	if (nbr == 0)
		ft_putstr(dict[0].value);
	div = 1000000000;
	while (div > 0)
	{
		if (nbr >= div)
		{
			print_three(nbr / div, dict);
			if (div > 1)
			{
				write(1, " ", 1);
				print_value(div, dict);
			}
			nbr %= div;
			if (nbr != 0)
				write(1, " ", 1);
		}
		div /= 1000;
	}
	write(1, "\n", 1);
}
