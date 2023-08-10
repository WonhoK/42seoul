/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:20 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/29 14:28:16 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	while (1)
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (result != 0 || s1[i] == '\0' || s2[i] == '\0')
			return (result);
		i++;
	}
	return (0);
}

char	**bubble_sort(char **arr, int len)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < len - i)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	int	i;

	argv = bubble_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
