/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:13:27 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/26 15:20:26 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		len++;
	}
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	int		num;
	char	result[32];

	i = 0;
	len = base_check(base);
	if (len < 2)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		write(1, "-", 1);
	while (nbr != 0)
	{
		num = nbr % len;
		if (num < 0)
			num *= (-1);
		result[i++] = base[num];
		nbr /= len;
	}
	while (i > 0)
		write(1, &result[--i], 1);
}
