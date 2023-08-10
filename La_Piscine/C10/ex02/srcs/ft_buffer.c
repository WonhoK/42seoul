/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:03:05 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 12:10:45 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*extend_buffer(char *buffer, int size)
{
	char	*new_buffer;
	int		i;

	new_buffer = (char *)malloc(sizeof(char) * size * 2);
	if (!new_buffer)
		return (0);
	i = 0;
	while (i < size)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

void	store_buf(char **buffer, int *buffer_size, int *byte_count, char c)
{
	if (*byte_count == *buffer_size)
	{
		*buffer = extend_buffer(*buffer, *buffer_size);
		*buffer_size *= 2;
	}
	(*buffer)[*byte_count] = c;
	(*byte_count)++;
}

void	write_buffer(int fd, char **buffer, int *byte_count, int *buf_size)
{
	char	read_buf[BUF_SIZE];
	int		read_size;
	int		i;

	while (1)
	{
		i = 0;
		read_size = read(fd, read_buf, BUF_SIZE);
		if (read_size < *buf_size)
			read_buf[read_size] = '\0';
		while (i < read_size)
			store_buf(buffer, buf_size, byte_count, read_buf[i++]);
		if (read_size <= 0)
			break ;
	}
}
