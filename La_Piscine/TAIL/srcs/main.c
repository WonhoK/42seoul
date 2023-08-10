/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:22:36 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 11:29:25 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	read_file(int argc, char **argv, int i, int byte_num)
{
	int	fd;
	int	file_num;

	file_num = argc - i;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(argv[i++], argv[0]);
			file_num--;
			continue ;
		}
		if (file_num > 1)
		{
			if (argc - i < file_num)
				write(1, "\n", 1);
			print_file_name(argv[i]);
		}
		ft_tail(fd, byte_num);
		close(fd);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int	i;
	int	byte_num;

	i = 1;
	byte_num = -1;
	if(argc == 1)
	{
		ft_tail(0, byte_num);
		return (0);
	}
	if (strcmp(argv[1], "-c") == 0)
	{
		if (argc == 2)
			return(print_error_no_option(argv[0]));
		if (ft_atoi(argv[2]) < 0)
			return(print_error_illegal_offset(argv[2], argv[0]));
		byte_num = ft_atoi(argv[2]);
		if (argc == 3)
			ft_tail(0, byte_num);
		i += 2;
	}
	read_file(argc, argv, i, byte_num);
	return (0);
}
