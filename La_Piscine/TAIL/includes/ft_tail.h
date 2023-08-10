/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:17:14 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/08 10:25:52 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define BUF_SIZE 1024

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
char	**extend_buffer(char **buffer, int size);
void	store_buf(char ***buffer, int *buffer_size, int *line_count, char *line);
void	free_buffer(char **buffer, int line_count);
void	write_buffer(int fd, char ***buffer, int *line_count, int *buf_size);
void	print_error(char *file, char *program);
int		print_error_no_option(char *program);
int		print_error_illegal_offset(char *file, char *program);
void	print_file_name(char *file);
void	ft_tail(int fd, int byte_num);
void	print_tail_line(char **buffer, int line_count);
void	print_tail_byte(char **buffer, int line_count, int byte_num);

#endif
