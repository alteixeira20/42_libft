/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:10:23 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 21:55:17 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tester.h"

int	main(void)
{
	FILE	*results;

	results = fopen("results.txt", "w");
	if (!results)
	{
		printf("Error: could not open results file.\n");
		return (1);
	}
	test_strlen(results);
	test_strlcpy(results);
	test_strlcat(results);
	test_strchr(results);
	test_strrchr(results);
	test_strncmp(results);
	test_strnstr(results);
	test_substr(results);
	test_strdup(results);
	test_strjoin(results);
	test_strtrim(results);
	test_split(results);
	test_isalpha(results);
	test_isdigit(results);
	test_isalnum(results);
	test_isascii(results);
	test_isprint(results);
	test_memset(results);
	test_memcpy(results);
	test_memchr(results);
	test_memmove(results);
	test_memcmp(results);
	test_bzero(results);
	test_calloc(results);
	test_tolower(results);
	test_toupper(results);
	test_atoi(results);
	test_putchar_fd(results);
	test_putstr_fd(results);
	test_putendl_fd(results);
	test_itoa(results);
	test_putnbr_fd(results);
	test_strmapi(results);
	test_striteri(results);
	test_lstnew(results);
	test_lstadd_front(results);
	test_lstadd_back(results);
	test_lstsize(results);
	test_lstlast(results);
	test_lstdelone(results);
	test_lstclear(results);
	test_lstiter(results);
	test_lstmap(results);
	fclose(results);
	return (0);
}
