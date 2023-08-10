/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   land.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:16:35 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 03:27:56 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	**generate_land(int size)
{
	int	cursor;
	int	**land;

	cursor = 0;
	land = (int **)malloc((size + 1) * sizeof(int *));
	while (cursor < size)
	{
		land[cursor] = (int *)malloc(size * sizeof(int));
		cursor++;
	}
	land[cursor] = NULL;
	return (land);
}

void	print_land(int **land, int size)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = land[i][j] + '0';
			write(1, &c, 1);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	free_land(int **land, int size)
{
	int	cursor;

	cursor = 0;
	while (cursor < size)
	{
		free(land[cursor]);
		cursor++;
	}
	free(land);
}

int	get_size(int **land)
{
	int	count;

	count = 0;
	while (land[count] != NULL)
		count++;
	return (count);
}
