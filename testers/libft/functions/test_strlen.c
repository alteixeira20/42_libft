/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:24:00 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/25 16:04:58 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <string.h>

void	test_strlen(FILE *results)
{
	const char	*str = "Hello, 42!";

	if (ft_strlen(str) == strlen(str))
		fprintf(results, "ft_strlen: SUCCESS\n");
	else
		fprintf(results, "ft_strlen: KO\n");
}
