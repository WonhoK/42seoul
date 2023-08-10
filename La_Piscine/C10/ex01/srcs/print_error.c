/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:22:20 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/05 18:22:52 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	print_error(char *File, char *Program)
{
	ft_putstr(basename(Program));
	write(1, ": ", 2);
	ft_putstr(File);
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
	errno = 0;
}
