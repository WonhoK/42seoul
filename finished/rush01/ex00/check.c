/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:29:03 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 03:29:11 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_land(int **land, int size);
int		get_size(int **land);

int		count_left(int **land, int fixed_line, int size);
int		count_right(int **land, int fixed_line, int size);
int		count_down_view(int **land, int fixed_col, int size);
int		count_up_view(int **land, int fixed_col, int size);

int	check_horizon(int **land, int **view, int row, int size)
{
	int	count[2];

	count[0] = count_left(land, row, size);
	count[1] = count_right(land, row, size);
	return (count[0] == view[2][row] && count[1] == view[3][row]);
}

int	check_vertical(int **land, int **view, int col, int size)
{
	int	count[2];

	count[0] = count_down_view(land, col, size);
	count[1] = count_up_view(land, col, size);
	return (count[0] == view[0][col] && count[1] == view[1][col]);
}

int	check_global(int **land, int **view, int size)
{
	int	testing;

	testing = 0;
	while (testing < size)
	{
		if (check_vertical(land, view, testing, size) == 1)
			testing++;
		else
			return (0);
	}
	return (1);
}

int	is_duplicated(int **land, int row, int col, int size)
{
	int	r;

	r = size - 1;
	while (r >= 0)
	{
		if (r != row && land[r][col] == land[row][col])
			return (1);
		r--;
	}
	return (0);
}

int	can_be_fulfilled(int **land, int **view, int fixed_line, int size)
{
	int	count[2];

	count[0] = count_left(land, fixed_line, size);
	count[1] = count_right(land, fixed_line, size);
	if (count[0] < view[2][fixed_line] || count[1] < view[3][fixed_line])
		return (0);
	return (1);
}
