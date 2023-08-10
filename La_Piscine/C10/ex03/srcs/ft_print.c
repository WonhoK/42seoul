/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:46:15 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/10 12:40:08 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_address(int add, int option)
{
	char	*hex;
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = option + 7;
	result = (char *)malloc(sizeof(char) * len);
	hex = "0123456789abcdef";
	while (i < len)
	{
		result[i++] = hex[add % 16];
		add /= 16;
	}
	while (i > 0)
		write(1, &result[--i], 1);
	free(result);
}

void	print_ascii(char *str, int option)
{
	int		i;
	char	a;
	char	b;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (option && i % 8 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		a = hex[str[i] / 16];
		b = hex[str[i] % 16];
		write(1, &a, 1);
		write(1, &b, 1);
		i++;
	}
	while (option && i < BUF_SIZE)
	{
		if (i % 8 == 0)
			write(1, " ", 1);
		write(1, "   ", 3);
		i++;
	}
}

void	print_char(char *str)
{
	write(1, "  |", 3);
	while (*str != '\0')
	{
		if (*str == '\n')
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
	}
	write(1, "|", 1);
}

void	print_star(int *add, int *flag)
{
	if (*flag == 0)
	{
		write(1, "*\n", 2);
		*flag = 1;
	}
	(*add) += 16;
}

void	print_whole(int *add, char *buf, int option)
{
	print_address(*add, option);
	print_ascii(buf, option);
	if (option)
		print_char(buf);
	write(1, "\n", 1);
	(*add) += ft_strlen(buf);
	//return (ft_strdup(buf));
}
