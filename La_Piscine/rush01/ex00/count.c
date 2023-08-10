/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:28:32 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 03:28:43 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_left(int **land, int fixed_line, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (max <= land[fixed_line][i])
		{
			count++;
			max = land[fixed_line][i];
		}
		i++;
	}
	return (count);
}

int	count_right(int **land, int fixed_line, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (max <= land[fixed_line][i])
		{
			count++;
			max = land[fixed_line][i];
		}
		i--;
	}
	return (count);
}

int	count_up_view(int **land, int fixed_col, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (max <= land[i][fixed_col])
		{
			count++;
			max = land[i][fixed_col];
		}
		i--;
	}
	return (count);
}

int	count_down_view(int **land, int fixed_col, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (max <= land[i][fixed_col])
		{
			count++;
			max = land[i][fixed_col];
		}
		i++;
	}
	return (count);
}
