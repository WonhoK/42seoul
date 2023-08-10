/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:29:25 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 03:29:41 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_horizon(int **land, int **view, int row, int size);
int		check_vertical(int **land, int **view, int col, int size);
int		check_global(int **land, int **view, int size);
int		is_duplicated(int **land, int row, int col, int size);

int		get_size(int **land);
void	print_land(int **land, int size);

int		can_be_fulfilled(int **land, int **view, int fixed_line, int size);

int	loop_start(int **land, int **view, int fixed_line, int num)
{
	int	pos;
	int	size;

	pos = 0;
	size = get_size(land);
	if (fixed_line < 0 && check_horizon(land, view, fixed_line + 1, size))
		return (check_global(land, view, size));
	if (num <= 0 && check_horizon(land, view, fixed_line, size))
		return (loop_start(land, view, fixed_line - 1, size));
	if (num <= 0 || fixed_line < 0)
		return (0);
	while (pos < size)
	{
		if (land[fixed_line][pos] == 0)
		{
			land[fixed_line][pos] = num;
			if (!is_duplicated(land, fixed_line, pos, size)
				&& can_be_fulfilled(land, view, fixed_line, size)
				&& loop_start(land, view, fixed_line, num - 1))
				return (1);
			land[fixed_line][pos] = 0;
		}
		pos++;
	}
	return (0);
}
