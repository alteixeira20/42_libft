/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:00:29 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 10:14:36 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	test_putchar_fd(FILE *results)
{
	char		test_char = 'A';
	int			fd;
	char		buffer[2] = {0};

	fd = open("test_putchar_fd.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		fprintf(results, "ft_putchar_fd: ERROR opening file\n");
		return ;
	}
	ft_putchar_fd(test_char, fd);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, buffer, 1) == 1 && buffer[0] == test_char)
		fprintf(results, "ft_putchar_fd: SUCCESS\n");
	else
		fprintf(results, "ft_putchar_fd: KO\n");
	close(fd);
}
