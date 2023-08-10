/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:28:57 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/24 17:50:04 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned int	p;
	unsigned int	q;
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	hex = "0123456789abcdef";
	temp = (unsigned char *)str;
	while (str[i] != '\0')
	{
		if (temp[i] < 32 || temp[i] > 126)
		{
			p = temp[i] / 16;
			q = temp[i] % 16;
			write(1, "\\", 1);
			write(1, &hex[p], 1);
			write(1, &hex[q], 1);
		}
		else
			write(1, &temp[i], 1);
		i++;
	}
}
