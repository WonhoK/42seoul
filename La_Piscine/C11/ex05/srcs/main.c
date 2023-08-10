/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:04:31 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/03 20:28:42 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_cal.h"

int	is_space(char c)
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

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	calculate(int a, int b, char op)
{
	if (op == '+')
		putnbr(add(a, b));
	else if (op == '-')
		putnbr(subtract(a, b));
	else if (op == '*')
		putnbr(multiply(a, b));
	else if (op == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			putnbr(divide(a, b));
	}
	else if (op == '%')
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			putnbr(mod(a, b));
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		op = argv[2][0];
		if (argv[2][1] != '\0')
			write(1, "0\n", 2);
		else if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
			write(1, "0\n", 2);
		else
			calculate(a, b, op);
	}
}
