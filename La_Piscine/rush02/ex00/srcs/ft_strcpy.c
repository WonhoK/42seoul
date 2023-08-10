/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:35:07 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 12:09:39 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = dest;
	src_ptr = src;
	while (*src_ptr != '\0')
	{
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
	}
	*dst_ptr = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*dst_ptr;
	char			*src_ptr;
	unsigned int	i;
	int				n_meet_nul;

	i = 0;
	n_meet_nul = 1;
	dst_ptr = dest;
	src_ptr = src;
	if (!src)
		return (dest);
	while (i < n)
	{
		*dst_ptr = *src_ptr;
		if (*src_ptr == '\0')
			n_meet_nul = 0;
		if (n_meet_nul)
			src_ptr++;
		dst_ptr++;
		i++;
	}
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ptr1;
	char			*ptr2;
	unsigned int	i;

	ptr1 = dest;
	ptr2 = src;
	i = 0;
	while (*ptr1 != '\0')
		ptr1++;
	while (*ptr2 != '\0' && i < nb)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		i++;
	}
	*ptr1 = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!result)
		return (0);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
