/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:25:23 by paalexan          #+#    #+#             */
/*   Updated: 2025/01/29 01:17:35 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include "../../libft/libft.h"

void	test_strlen(FILE *results);
void	test_strlcpy(FILE *results);
void	test_strlcat(FILE *results);
void	test_strchr(FILE *results);
void	test_strrchr(FILE *results);
void	test_strncmp(FILE *results);
void	test_strnstr(FILE *results);
void	test_strdup(FILE *results);
void	test_substr(FILE *results);
void	test_strjoin(FILE *results);
void	test_strtrim(FILE *results);
void	test_split(FILE *results);
void	test_isdigit(FILE *results);
void	test_isalpha(FILE *results);
void	test_isalnum(FILE *results);
void	test_isascii(FILE *results);
void	test_isprint(FILE *results);
void	test_memset(FILE *results);
void	test_memcpy(FILE *results);
void	test_memchr(FILE *results);
void	test_memmove(FILE *results);
void	test_memcmp(FILE *results);
void	test_bzero(FILE *results);
void	test_calloc(FILE *results);
void	test_tolower(FILE *results);
void	test_toupper(FILE *results);
void	test_atoi(FILE *results);
void	test_putchar_fd(FILE *results);
void	test_putstr_fd(FILE *results);
void	test_putendl_fd(FILE *results);
void	test_itoa(FILE *results);
void	test_putnbr_fd(FILE *results);
void	test_strmapi(FILE *results);
void	test_striteri(FILE *results);

void	test_lstnew(FILE *results);
void	test_lstadd_front(FILE *results);
void	test_lstadd_back(FILE *results);
void	test_lstsize(FILE *results);
void	test_lstlast(FILE *results);
void	test_lstdelone(FILE *results);
void	test_lstclear(FILE *results);
void	test_lstiter(FILE *results);
void	test_lstmap(FILE *results);
#endif
