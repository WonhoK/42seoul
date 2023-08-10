/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhkim <wonhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:28:51 by wonhkim           #+#    #+#             */
/*   Updated: 2023/08/05 16:19:19 by wonhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	unsigned char	buf[1024];
	int				fd;
	int				size;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			write(2, "Cannot read file.\n", 18);
		while (1)
		{
			size = read(fd, buf, 1023);
			if (size == 0)
				break ;
			write(1, buf, size);
		}
		close(fd);
	}
	return (0);
}
