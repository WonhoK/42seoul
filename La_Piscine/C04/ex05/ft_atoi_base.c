/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:14:16 by wonhkim           #+#    #+#             */
/*   Updated: 2023/07/26 15:54:59 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space_2(char c)
{
	char	*space;

	space = " \n\t\v\f\r";
	while (*space != '\0')
	{
		if (c == *space)
			return (1);
		space++;
	}
	return (0);
}

int	base_check_2(char *base)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (base[len] != '\0')
	{
		if (is_space_2(base[len]) || base[len] == '-' || base[len] == '+')
			return (0);
		len++;
	}
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

int	find_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_simple(char *str, char *base, int len)
{
	int	result;
	int	temp;

	result = 0;
	temp = 0;
	while (1)
	{
		temp = find_base(base, *str++);
		if (temp < 0)
			break ;
		result = result * len + temp;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	count;
	int	len;

	nbr = 0;
	count = 0;
	len = base_check_2(base);
	if (len < 2)
		return (0);
	while (is_space_2(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	nbr = atoi_simple(str, base, len);
	if (count % 2 == 1)
		return (nbr * (-1));
	return (nbr);
}
