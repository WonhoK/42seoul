/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:17:14 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 19:24:26 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

void	print_error(char *File, char *Program);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	display_file(int fd, char *File, char *Program);

#endif
