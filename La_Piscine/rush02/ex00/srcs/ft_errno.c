/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:33:55 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 12:41:12 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*free_with_set_errno(char **ptr, int *errno)
{
	if (ptr)
		free(ptr);
	*errno = 1;
	return (0);
}

int	free_with_errno(char *target, int *errno)
{
	if (target)
		free(target);
	return (*errno);
}
