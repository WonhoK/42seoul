/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:17:48 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/06 15:26:30 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_dict.h"

char	*int_to_char(char *key, int num)
{
	int	len;
	int	temp;

	temp = num;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	key[len] = '\0';
	while (len >= 0)
	{
		key[--len] = num % 10 + '0';
		num /= 10;
	}
	return (key);
}

void	init_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 32)
		dict[i++].value = 0;
	i = 0;
	while (i < 21)
	{
		int_to_char(dict[i].key, i);
		i++;
	}
	while (i < 29)
	{
		int_to_char(dict[i].key, (i % 10 + 2) * 10);
		i++;
	}
	int_to_char(dict[29].key, 1000);
	int_to_char(dict[30].key, 1000000);
	int_to_char(dict[31].key, 1000000000);
}

int	is_valid_key(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	add_val(char *key, char *value, t_dict *dict)
{
	int	idx;

	if (!ft_is_printable(value))
		return (1);
	idx = is_valid_key(key, dict);
	if (idx >= 0)
		dict[idx].value = value;
	return (0);
}

char	*get_value(char *key, t_dict *dict)
{
	int	idx;

	idx = is_valid_key(key, dict);
	if (idx >= 0)
		return (dict[idx].value);
	return (0);
}
