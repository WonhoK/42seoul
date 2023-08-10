/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:21:54 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/31 13:08:25 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	rg;
	int	i;

	rg = max - min;
	if (rg <= 0)
		return (0);
	ptr = (int *)malloc(sizeof(int) * rg);
	if (ptr == 0)
		return (0);
	i = 0;
	while (min < max)
		ptr[i++] = min++;
	*range = ptr;
	return (rg);
}
