/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:16:58 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/25 16:02:20 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"

void	test_isalnum(FILE *results)
{
	if (ft_isalnum('A') && ft_isalnum('0'))
		fprintf(results, "ft_isalnum: SUCCESS\n");
	else
		fprintf(results, "ft_isalnum: KO\n");
}
