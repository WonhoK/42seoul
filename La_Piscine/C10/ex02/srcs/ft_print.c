/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:43:50 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 12:10:49 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_file_name(char *file)
{
	write(1, "==> ", 4);
	ft_putstr(file);
	write(1, " <==\n", 5);
}

int	print_error_illegal_offset(char *file, char *program)
{
	ft_putstr(basename(program));
	write(1, ": illegal offset -- ", 20);
	ft_putstr(file);
	write(1, "\n", 1);
	return (0);
}

void	print_error(char *file, char *program)
{
	ft_putstr(basename(program));
	write(1, ": ", 2);
	ft_putstr(file);
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
	errno = 0;
}

int	print_error_no_option(char *program)
{
	ft_putstr(basename(program));
	write(1, ": option requires an argument -- c\n", 36);
	write(1, "usage: tail [-F | -f | -r]", 26);
	write(1, "[-q] [-b # | -c # | -n #] [file ...]\n", 37);
	return (0);
}

void	print_tail(char *buffer, int byte_count, int byte_num)
{
	int	start_index;
	int	print_byte;
	int	i;

	if (byte_count > byte_num)
	{
		start_index = byte_count - byte_num;
		print_byte = byte_num;
	}
	else
	{
		start_index = 0;
		print_byte = byte_count;
	}
	i = 0;
	while (i < print_byte)
	{
		write(1, &buffer[start_index + i], 1);
		i++;
	}
}
