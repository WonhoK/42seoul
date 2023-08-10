/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:35:04 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/10 12:36:41 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define BUF_SIZE 16
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_str_is_same(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strdup(char *src);
char	*ft_strcat(char *dest, char *src);
void	ft_str_index_cpy(char **buf, char *read_buf, int index);
void	print_address(int add, int option);
void	print_whole(int *add, char *buf, int option);
void	print_star(int *add, int *flag);
void	print_error(char *file, char *program);

#endif
