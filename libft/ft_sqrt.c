/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:29:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/10/04 17:14:09 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double		ft_sqrt(double x)
{
	double temp;
	double sqrt;

	sqrt = x / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (x / temp + temp) / 2;
	}
	return (sqrt);
}
