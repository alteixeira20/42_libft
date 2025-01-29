/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:19:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/25 01:20:45 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"

void	test_isdigit(FILE *results)
{
	if (ft_isdigit('0'))
		fprintf(results, "ft_isdigit: SUCCESS\n");
	else
		fprintf(results, "ft_isdigit: KO\n");
}
