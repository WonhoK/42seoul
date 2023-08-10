/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:15 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 12:05:56 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_char_in_str(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split_connecter(char *str, char **str_list, const int str_len)
{
	int	i;
	int	str_list_i;

	str_list_i = 0;
	i = 0;
	while (i < str_len)
	{
		if (str[i] != '\0' && (str[i - 1] == '\0' || i == 0))
		{
			str_list[str_list_i] = &str[i];
			if (!str_list[str_list_i])
				return (0);
			str_list_i++;
		}
		i++;
	}
	str_list[str_list_i] = 0;
	return (str_list);
}

char	**ft_split(char *str, char *charset)
{
	int			str_list_size;
	int			i;
	char		*temp_str;
	char		**str_list;

	temp_str = ft_strdup(str);
	if (!temp_str)
		return (0);
	i = 0;
	str_list_size = 1;
	while (i < ft_strlen(str))
	{
		if (ft_char_in_str(temp_str[i], charset))
		{
			temp_str[i] = '\0';
			if (i != 0 && temp_str[i - 1] != '\0')
				str_list_size++;
		}
		i++;
	}
	str_list = (char **)malloc(sizeof(char *) * (str_list_size + 1));
	if (!str_list)
		return (0);
	return (ft_split_connecter(temp_str, str_list, ft_strlen(str)));
}
