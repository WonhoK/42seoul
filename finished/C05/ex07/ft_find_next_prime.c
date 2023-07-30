/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:16:00 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/27 10:33:30 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int num)
{
	long	i;
	long	temp;

	i = 2;
	if (num <= 1)
		return (0);
	if (num == 2)
		return (1);
	while (1)
	{
		if (num % i == 0)
			return (0);
		temp = i * i;
		if (temp > num)
			break ;
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	result;

	result = nb;
	while (1)
	{
		if (is_prime(result))
			return (result);
		result++;
	}
}
