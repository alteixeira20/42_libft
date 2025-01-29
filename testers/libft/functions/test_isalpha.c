/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:16:58 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/25 01:18:27 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"

void	test_isalpha(FILE *results)
{
	if (ft_isalpha('A'))
		fprintf(results, "ft_isalpha: SUCCESS\n");
	else
		fprintf(results, "ft_isalpha: KO\n");
}
