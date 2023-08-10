/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:55:02 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/03 15:14:52 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	cnt;
	int	temp;
	int	i;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		temp = f(tab[i++]);
		if (temp != 0)
			cnt++;
	}
	return (cnt);
}
