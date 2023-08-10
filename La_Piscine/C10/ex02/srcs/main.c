/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:22:36 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 19:25:37 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(int fd, int byte_num)
{
	char	*buffer;
	int		byte_count;
	int		buf_size;

	buffer = (char *)malloc(sizeof(char) * BUF_SIZE);
	buf_size = BUF_SIZE;
	byte_count = 0;
	write_buffer(fd, &buffer, &byte_count, &buf_size);
	print_tail(buffer, byte_count, byte_num);
	free(buffer);
}

void	read_file(int argc, char **argv, int byte_num)
{
	int	fd;
	int	i;
	int	file_num;

	i = 3;
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
		if (argc > 4)
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
	int	byte_num;

	if (argc == 2)
		return (print_error_no_option(argv[0]));
	if (ft_atoi(argv[2]) < 0)
		return (print_error_illegal_offset(argv[2], argv[0]));
	byte_num = ft_atoi(argv[2]);
	if (argc == 3)
		ft_tail(0, byte_num);
	else
		read_file(argc, argv, byte_num);
	return (0);
}
