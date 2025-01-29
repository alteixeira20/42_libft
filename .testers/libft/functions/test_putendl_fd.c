/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:46 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 16:45:50 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	test_putendl_fd(FILE *results)
{
	char	*test_str = "Hello, 42!";
	int			fd;
	char		buffer[50] = {0};  // Large enough to hold the test string and newline
	size_t		expected_len;

	fd = open("test_putendl_fd.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		fprintf(results, "ft_putendl_fd: ERROR opening file\n");
		return ;
	}
	ft_putendl_fd(test_str, fd);
	lseek(fd, 0, SEEK_SET);
	expected_len = strlen(test_str) + 1;  // +1 for newline
	if (read(fd, buffer, expected_len) == (ssize_t)expected_len &&
		strcmp(buffer, "Hello, 42!\n") == 0)
	{
		fprintf(results, "ft_putendl_fd: SUCCESS\n");
	}
	else
	{
		fprintf(results, "ft_putendl_fd: KO\n");
	}
	close(fd);
}
