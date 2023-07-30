/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:37:54 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/26 16:43:06 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int					i;
	unsigned long long	result;

	i = 2;
	result = 1;
	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	while (i <= nb)
		result *= (unsigned long long) i++;
	return (result);
}
