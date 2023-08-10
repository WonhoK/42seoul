/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:25:44 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/20 19:32:52 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recurse(int n, int depth, char *result)
{
	char	sep[2];
	int		num;

	sep[0] = ',';
	sep[1] = ' ';
	num = result[depth - 1] + 1;
	if (depth == n)
	{
		write(1, result, n);
		if (result[0] != 10 - n + '0')
			write(1, &sep, 2);
	}
	else
	{
		while (num <= '9')
		{
			result[depth] = num;
			recurse(n, depth + 1, result);
			num++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;

	i = 0;
	while (i <= 10 - n)
	{
		arr[0] = '0' + i;
		recurse(n, 1, arr);
		i++;
	}
}
