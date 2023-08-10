/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:19:02 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 16:11:11 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_dict.h"
#include <fcntl.h>
#define BUF_SIZE 64

char	*free_with_set_errno(char **ptr, int *errno);
int		free_with_errno(char *target, int *errno);

int	get_strs_size(char **strs)
{
	int	size;

	size = 0;
	while (strs[size])
		size++;
	return (size);
}

char	*parsing(char *str, int read_size, int *en, t_dict *arr)
{
	char	**strs;
	int		i;
	int		col_i;
	int		str_size;

	strs = ft_split(str, "\n");
	if (!strs)
		return (free_with_set_errno(strs, en));
	str_size = get_strs_size(strs);
	*en = 0;
	i = 0;
	if (read_size < BUF_SIZE)
		str_size++;
	while (i < str_size - 1 && strs[i])
	{
		col_i = get_char_idx_str(':', strs[i]);
		if (col_i < 0)
			return (free_with_set_errno(strs, en));
		strs[i][col_i] = '\0';
		*en += add_val(ft_strip_i(strs[i]), ft_strip(&strs[i][col_i + 1]), arr);
		i++;
	}
	free(strs);
	return (strs[str_size - 1]);
}

char	*extend_store(char *store, int *s_size, int *errno)
{
	char	*new_store;

	new_store = (char *)malloc(sizeof(char) * (*s_size) * 2);
	if (!new_store)
	{
		*errno = 1;
		return (0);
	}
	ft_strncpy(new_store, store, *s_size);
	free(store);
	*s_size *= 2;
	return (new_store);
}

int	file_read(int fd, t_dict *arr)
{
	char	buf[BUF_SIZE];
	char	*store;
	int		errno;
	int		s_size;
	int		read_size;

	s_size = BUF_SIZE * 2 + 1;
	store = (char *)malloc(sizeof(char) * s_size);
	if (!store)
		return (1);
	store[0] = '\0';
	while (1)
	{
		read_size = read(fd, buf, BUF_SIZE);
		if (read_size < BUF_SIZE)
			buf[read_size] = '\0';
		store = ft_strncat(store, buf, BUF_SIZE);
		if (get_char_idx_str('\n', store) > -1)
			ft_strncpy(store, parsing(store, read_size, &errno, arr), s_size);
		else if (s_size - ft_strlen(store) <= BUF_SIZE)
			store = extend_store(store, &s_size, &errno);
		if (read_size < BUF_SIZE || errno)
			break ;
	}
	return (free_with_errno(store, &errno));
}

int	read_main(char *file_name, t_dict *arr)
{
	int	fd;
	int	errno;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
	errno = file_read(fd, arr);
	if (close(fd) < 0)
		return (1);
	return (errno);
}
