/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:43:39 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 16:47:31 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	test_putnbr_fd(FILE *results)
{
	int		test_num = 12345;
	int		fd;
	char	buffer[50] = {0};  // Large enough to hold the number string
	size_t	expected_len;

	fd = open("test_putnbr_fd.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		fprintf(results, "ft_putnbr_fd: ERROR opening file\n");
		return ;
	}
	ft_putnbr_fd(test_num, fd);
	lseek(fd, 0, SEEK_SET);

	// Convert test_num to string and calculate expected length
	char expected_str[50];
	sprintf(expected_str, "%d", test_num);
	expected_len = strlen(expected_str);

	// Read and compare the output
	if (read(fd, buffer, expected_len) == (ssize_t)expected_len &&
		strcmp(buffer, expected_str) == 0)
	{
		fprintf(results, "ft_putnbr_fd: SUCCESS\n");
	}
	else
	{
		fprintf(results, "ft_putnbr_fd: KO | Expected: \"%s\", Got: \"%s\"\n", expected_str, buffer);
	}
	close(fd);
}
