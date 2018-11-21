/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:08:02 by ochaar            #+#    #+#             */
/*   Updated: 2018/11/21 11:04:47 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb)
{
	long	result;

	result = 1;
	while (result * result < nb)
		result ++;
	return ((int)result);
}
