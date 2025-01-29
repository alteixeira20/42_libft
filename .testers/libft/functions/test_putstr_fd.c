/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:10:07 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 10:14:23 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	test_putstr_fd(FILE *results)
{
	char	*test_str = "Hello, 42!";
	int			fd;
	char		buffer[50] = {0};  // Large enough to hold the test string

	fd = open("test_putstr_fd.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		fprintf(results, "ft_putstr_fd: ERROR opening file\n");
		return ;
	}
	ft_putstr_fd(test_str, fd);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, buffer, strlen(test_str)) == (ssize_t)strlen(test_str) &&
		strcmp(buffer, test_str) == 0)
	{
		fprintf(results, "ft_putstr_fd: SUCCESS\n");
	}
	else
	{
		fprintf(results, "ft_putstr_fd: KO\n");
	}
	close(fd);
}
