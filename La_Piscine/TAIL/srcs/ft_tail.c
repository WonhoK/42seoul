/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:57:53 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 11:30:08 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_tail_line(char **buffer, int line_count)
{
	int	start_line;
	int	print_line;
	int	len;
	int	i;

	if (line_count > 10)
	{
		start_line = line_count - 10;
		print_line = 10;
	}
	else
	{
		start_line = 0;
		print_line = line_count;
	}
	i = 0;
	while (i < print_line)
	{
		len = ft_strlen(buffer[start_line + i]);
		write(1, buffer[start_line + i], len);
		write(1, "\n", 1);
		i++;
	}
}

void	print_tail_byte(char **buffer, int line_count, int byte_num)
{
	char	*result;
	int		buf_idx;
	int		i;

	buf_idx = line_count - 1;
	i = ft_strlen(buffer[buf_idx]) - 1;
	result = (char *)malloc(sizeof(char) * byte_num);
	if (!result)
		return ;
	result[byte_num--] = '\0';
	while (buf_idx >= 0 && 0 < byte_num)
	{
		result[--byte_num] = buffer[buf_idx][i];
		i--;
		if (byte_num <= 0)
			break ;
		if (i < 0)
		{
			result[--byte_num] = '\n';
			buf_idx--;
			i = ft_strlen(buffer[buf_idx]) - 1;
		}
	}
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
}

void	ft_tail(int fd, int byte_num)
{
	char	**buffer;
	int		line_count;
	int		buf_size;

	buffer = (char **)malloc(sizeof(char) * BUF_SIZE);
	buf_size = BUF_SIZE;
	line_count = 0;
	write_buffer(fd, &buffer, &line_count, &buf_size);
	if (byte_num < 0)
		print_tail_line(buffer, line_count);
	else
		print_tail_byte(buffer, line_count, byte_num);
	free_buffer(buffer, line_count);
}
