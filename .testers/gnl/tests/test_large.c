/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:06:08 by paalexan          #+#    #+#             */
/*   Updated: 2025/01/29 03:08:47 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../gnl/get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int	fd = open("tests/test_cases/big_line_with_nl", O_RDONLY);
	if (fd < 0) {
		perror("Error opening file");
		return (1);
	}

	char	*line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
