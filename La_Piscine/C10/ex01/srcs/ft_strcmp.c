/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:20:57 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/25 17:06:29 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	int				result;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	result = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (1)
	{
		result = str1[i] - str2[i];
		if (result != 0)
			break ;
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return (result);
}
