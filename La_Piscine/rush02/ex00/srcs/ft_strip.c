/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:15:45 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 15:25:17 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_string.h"

char	*ft_strip(char *str)
{
	const int	len = ft_strlen(str);
	int			left_i;
	int			right_i;

	left_i = 0;
	right_i = len - 1;
	while (get_char_idx_str(str[left_i], "\t\n\r\v\f ") > -1)
		left_i++;
	while (get_char_idx_str(str[right_i], "\t\n\r\v\f ") > -1)
		right_i--;
	str[right_i + 1] = '\0';
	return (&str[left_i]);
}

char	*ft_strip_i(char *str)
{
	const int	len = ft_strlen(str);
	int			left_i;
	int			last_i;

	left_i = 0;
	last_i = len - 1;
	while (get_char_idx_str(str[left_i], "\t\n\r\v\f ") > -1)
		left_i++;
	last_i = left_i;
	if (str[left_i] == '+' || str[left_i] == '-')
	{
		if (str[left_i] == '+')
			left_i++;
		last_i++;
	}
	while (check_numeric(str[last_i]))
		last_i++;
	str[last_i] = '\0';
	return (&str[left_i]);
}
