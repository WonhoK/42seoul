/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:30:28 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/23 14:38:41 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	p;
	int	q;
	int	div;
	int	mod;

	p = *a;
	q = *b;
	div = p / q;
	mod = p % q;
	*a = div;
	*b = mod;
}
