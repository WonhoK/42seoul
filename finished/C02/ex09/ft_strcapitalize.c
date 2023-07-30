/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:16:29 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/24 20:15:54 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_flag(char c)
{	
	if (c >= '0' && c <= '9')
		return (3);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag == 1)
		{
			flag = 0;
			if (check_flag(str[i]) == 0)
				flag = 1;
			else if (check_flag(str[i]) == 1)
				str[i] -= 32;
		}
		else
		{
			if (check_flag(str[i]) == 0)
				flag = 1;
			else if (check_flag(str[i]) == 2)
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
