/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:19:40 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/10 12:41:58 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

void	restore(char **buf)
{
	int	i;

	i = 0;
	while (i <= BUF_SIZE)
	{
		(*buf)[i] = (*buf)[BUF_SIZE + i];
		i++;
	}
}
void	read_file(int fd, char **buf, int *add, int option)
{
	int		flag;
	int		read_size;
	char	read_buf[BUF_SIZE + 1];
	char	print_buf[BUF_SIZE + 1];

	flag = 0;
	while (1)
	{
		read_size = read(fd, read_buf, BUF_SIZE);
		if (read_size <= 0)
			break ;
		read_buf[read_size] = '\0';
		*buf = ft_strcat(*buf, read_buf);
		if (ft_strlen(*buf) >= BUF_SIZE)
		{
			print_buf = ft_strncpy(print_buf, *buf, BUF_SIZE);
			print_whole(add, print_buf, option);
			restore(buf);
		}
	}
}

void	ft_hexdump(int argc, char **argv, char **buf, int add)
{
	int	i;
	int	fd;
	int	option;

	option = ft_str_is_same(argv[1], "-C");
	i = 1 + option;
	while (i < argc)
	{
		fd = open(argv[i++], O_RDONLY);
		if (fd < 0)
			print_error(argv[i - 1], argv[0]);
		read_file(fd, buf, &add, option);
		close(fd);
	}
}

int	main(int argc, char **argv)
{
	int		add;
	char	*buf;

	add = 0;
	buf = (char *)malloc(sizeof(char) * (2 * BUF_SIZE + 1));
	buf[0] = '\0';
	if (argc == 1)
	{
		read_file(0, &buf, &add, 0);
		print_address(add, 0);
	}
	else if (argc == 2 && ft_str_is_same(argv[1], "-C"))
	{
		read_file(0, &buf, &add, 1);
		print_address(add, 1);
	}
	else
		ft_hexdump(argc, argv, &buf, add);
	free(buf);
	return (0);
}
