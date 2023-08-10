/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:03:05 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 11:31:05 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	free_buffer(char **buffer, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

char	**extend_buffer(char **buffer, int size)
{
	char	**new_buffer;
	int		i;

	new_buffer = (char **)malloc(sizeof(char) * size * 2);
	if (!new_buffer)
		return (0);
	i = 0;
	while (i < size)
	{
		new_buffer[i] = strdup(buffer[i]);
		i++;
	}
	free_buffer(buffer, size);
	return (new_buffer);
}

void	store_buf(char ***buffer, int *buffer_size, int *line_count, char *line)
{
	if (*line_count == *buffer_size)
	{
		*buffer = extend_buffer(*buffer, *buffer_size);
		*buffer_size *= 2;
	}
	(*buffer)[*line_count] = ft_strdup(line);
	(*line_count)++;
}

void	write_buffer(int fd, char ***buffer, int *line_count, int *buf_size)
{
	int		line_start;
	char	read_buf[BUF_SIZE];
	int		read_size;
	int		i;

	i = 0;
	while (1)
	{
		line_start = 0;
		read_size = read(fd, read_buf, BUF_SIZE);
		i = 0;
		while (i < read_size)
		{
			if (read_buf[i] == '\n' || read_buf[i] == '\0')
			{
				read_buf[i] = '\0';
				store_buf(buffer, buf_size, line_count, &read_buf[line_start]);
				line_start = i + 1;
			}
			i++;
		}
		if (read_size <= 0)
			break ;
	}
}
