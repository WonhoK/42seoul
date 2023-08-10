/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:16:36 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/07 13:57:44 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	display_file(int fd, char *file, char *program)
{
	unsigned char	buf[1024];
	int				size;

	while (1)
	{
		size = read(fd, buf, 1023);
		if (size == 0)
			break ;
		if (errno)
		{
			print_error(file, program);
			break ;
		}
		write(1, buf, size);
	}
}
