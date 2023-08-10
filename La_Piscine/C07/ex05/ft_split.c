/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:04:12 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/31 13:36:26 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	while (*sep != '\0')
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

char	*str_dup(char *str, char *charset)
{
	int		len;
	char	*dest;
	int		i;

	len = 0;
	while (str[len] != '\0' && !is_sep(str[len], charset))
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	element_count(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			cnt++;
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		num;
	int		i;
	char	**result;

	num = element_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (num + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			result[i++] = str_dup(str, charset);
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}
