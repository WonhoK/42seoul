/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:59:40 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 09:02:29 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		**accept_view(char *input, int *n_out);
int		**generate_land(int size);
void	print_land(int **land, int size);
void	free_land(int **land, int size);
int		loop_start(int **land, int **view, int fixed_line, int num);
void	free_view(int **view);

int	main(int argc, char **argv)
{
	int	**view;
	int	**land;
	int	n;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	view = accept_view(argv[1], &n);
	if (view == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	land = generate_land(n);
	if (loop_start(land, view, n - 1, n))
		print_land(land, n);
	else
		write(1, "Error\n", 6);
	free_land(land, n);
	free_view(view);
	return (0);
}
