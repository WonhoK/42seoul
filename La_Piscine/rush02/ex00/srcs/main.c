/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:02 by minjacho          #+#    #+#             */
/*   Updated: 2023/08/06 16:56:25 by minjacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "ft_string.h"
#include "ft_dict.h"

int	read_main(char *file_name, t_dict *arr);

char	*ft_argument_parse(char *argv)
{
	int	i;
	int	start;

	i = 0;
	argv = ft_strip(argv);
	if (argv[i] == '+')
		i++;
	start = i;
	if (argv[i] == '\0')
		return (0);
	while (argv[i] == '0')
		i++;
	if (argv[i] == '\0')
		return (&argv[i - 1]);
	start = i;
	while (argv[i])
	{
		if (!check_numeric(argv[i]))
			return (0);
		i++;
	}
	if (i - start > 12)
		return (0);
	return (&argv[start]);
}	

int	check_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (!dict[i].value)
		{
			write(1, "Dict Error\n", 12);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_stdin_num(t_dict *dict)
{
	char	buf[1025];
	int		size;

	while (1)
	{
		size = read(0, buf, 1024);
		buf[size] = '\0';
		if (size < 1)
			break ;
		if (!ft_argument_parse(buf))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		ft_strcpy(buf, ft_argument_parse(buf));
		print_whole(buf, dict);
	}
	if (size < 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*file_name;
	t_dict	dict[32];

	if (argc > 3)
		return (0);
	init_dict(dict);
	file_name = "numbers.dict";
	if (argc == 3)
		file_name = argv[1];
	if (read_main(file_name, dict))
	{
		write(1, "Dict Error\n", 12);
		return (1);
	}
	if (!check_dict(dict))
		return (1);
	if (argc == 1)
		return (get_stdin_num(dict));
	argv[argc - 1] = ft_argument_parse(argv[argc - 1]);
	if (!argv[argc - 1])
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_whole(argv[argc - 1], dict);
}
