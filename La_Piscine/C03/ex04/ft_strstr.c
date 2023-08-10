/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:47:02 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/25 19:22:26 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		check;
	int		i;
	int		j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		check = 1;
		j = 0;
		while (to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j] || str[i] == '\0')
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check)
			return (&str[i]);
		i++;
	}
	return (0);
}
