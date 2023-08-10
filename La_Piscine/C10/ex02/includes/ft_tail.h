/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:17:14 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 19:24:47 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define BUF_SIZE 1024

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

int		ft_atoi(char *str);
void	ft_putstr(char *str);
char	*extend_buffer(char *buffer, int size);
void	store_buf(char **buffer, int *buffer_size, int *byte_count, char c);
void	write_buffer(int fd, char **buffer, int *byte_count, int *buf_size);
void	print_error(char *file, char *program);
int		print_error_no_option(char *program);
int		print_error_illegal_offset(char *file, char *program);
void	print_file_name(char *file);
void	print_tail(char *buffer, int byte_count, int byte_num);

#endif
