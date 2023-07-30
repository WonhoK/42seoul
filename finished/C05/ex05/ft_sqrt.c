/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:08:09 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/26 20:05:40 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	temp;

	i = 0;
	temp = 0;
	if (nb < 1)
		return (0);
	while (1)
	{
		temp = i * i;
		if (temp == nb)
			return (i);
		else if (temp > nb)
			return (0);
		i++;
	}
}
