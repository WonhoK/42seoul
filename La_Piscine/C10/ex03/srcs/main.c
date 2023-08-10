/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:19:40 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/10 15:18:49 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

int	fill_buf(char **buf, char *read_buf, char **print_buf)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while ((*buf)[i] != '\0')
		i++;
	while (i < BUF_SIZE && read_buf[j] != '\0')
		(*buf)[i++] = read_buf[j++];
	(*buf)[i] = '\0';
	*print_buf = ft_strdup(*buf);
	if (i == BUF_SIZE)
	{
		(*buf)[0] = '\0';
		ret = 1;
	}
	i = 0;
	while ((*buf)[i] != '\0')
		i++;
	while (read_buf[j] != '\0')
		(*buf)[i++] = read_buf[j++];
	(*buf)[i] = '\0';
	return (ret);
}

void	read_file(int fd, char **buf, int *add, int option)
{
	int		flag;
	int		read_size;
	char	read_buf[BUF_SIZE + 1];
	char	*print_buf;
	char	*prev_buf;

	flag = 0;
	while (1)
	{
		read_size = read(fd, read_buf, BUF_SIZE);
		if (read_size <= 0)
			break ;
		read_buf[read_size] = '\0';
		if (fill_buf(buf, read_buf, &print_buf))
		{
			if (prev_buf != 0 && ft_str_is_same(prev_buf, print_buf))
				print_star(add, &flag);
			else
			{
				print_whole(add, print_buf, option, &flag);
				prev_buf = ft_strdup(print_buf);
			}
		}
	}
}

void	ft_hexdump(int argc, char **argv, char **buf, int add)
{
	int	i;
	int	fd;
	int	option;
	int	flag;

	flag = 0;
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
	print_whole(&add, *buf, option, &flag);
}

int	main(int argc, char **argv)
{
	int		add;
	char	*buf;
	int		flag;

	add = 0;
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	buf[0] = '\0';
	flag = 0;
	if (argc == 1)
	{
		read_file(0, &buf, &add, 0);
		print_whole(&add, buf, 0, &flag);
	}
	else if (argc == 2 && ft_str_is_same(argv[1], "-C"))
	{
		read_file(0, &buf, &add, 1);
		print_whole(&add, buf, 1, &flag);
	}
	else
		ft_hexdump(argc, argv, &buf, add);
	free(buf);
	return (0);
}
