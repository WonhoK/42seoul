/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:22:53 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/30 03:27:20 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	is_acceptable(char *str, int n)
{
	int	cursor;

	cursor = 0;
	while (str[cursor] != '\0')
	{
		if (cursor % 2 == 1 && str[cursor] != ' ')
			return (0);
		else if (cursor % 2 == 0 && (str[cursor] < '0' || str[cursor] > '9'))
			return (0);
		else if (cursor % 2 == 0
			&& (str[cursor] <= '9' && str[cursor] > (n + '0')))
			return (0);
		cursor++;
	}
	return (1);
}

void	append_num(int **view, char *str, int *cursor, int n)
{
	int	*new_data;
	int	count_data;

	new_data = (int *)malloc(n * sizeof(int));
	count_data = 0;
	while (count_data < n)
	{
		if (str[*cursor] != ' ')
			new_data[count_data++] = str[*cursor] - '0';
		(*cursor)++;
	}
	view[(*cursor) / (2 * n)] = new_data;
}

int	**accept_view(char *input, int *n_out)
{
	int		len;
	int		n;
	int		**view;
	int		cursor;

	len = ft_strlen(input);
	n = (len + 1) / 8;
	if (len >= 72 || !is_acceptable(input, n) || ((len + 1) % 8) != 0)
		return (NULL);
	view = (int **) malloc(4 * sizeof(int *));
	cursor = 0;
	while (cursor < len + 1)
	{
		append_num(view, input, &cursor, n);
		cursor++;
	}
	*n_out = n;
	return (view);
}
