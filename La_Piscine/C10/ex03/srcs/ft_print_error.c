/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:31:18 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/10 10:47:57 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

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
