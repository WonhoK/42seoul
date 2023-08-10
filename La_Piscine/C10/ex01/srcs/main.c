/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:28:51 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 18:49:07 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	std_in_out(void)
{
	unsigned char	buf[1024];
	int				size;

	while (1)
	{
		size = read(0, buf, 1024);
		write(1, buf, size);
		if (size == 0)
			return (0);
	}
}

int	main(int argc, char **argv)
{
	int				fd;
	int				i;

	if (argc == 1)
		return (std_in_out());
	if (argc == 2 && (!ft_strcmp(argv[1], "-") || !ft_strcmp(argv[1], "--")))
		return (std_in_out());
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(argv[i], argv[0]);
			i++;
			continue ;
		}
		display_file(fd, argv[i], argv[0]);
		i++;
		if (close(fd) < 0)
			return (1);
	}
	return (0);
}
