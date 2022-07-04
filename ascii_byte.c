/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkucukku <mkucukku@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:21:47 by mkucukku          #+#    #+#             */
/*   Updated: 2022/04/12 16:22:04 by mkucukku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*ascii_byte(int c)
{
	int		i;
	int		value;
	int		*str;

	i = 0;
	value = 0;
	str = (int *)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		value = c / ft_iterative_power(2, i);
		if (value % 2 == 0)
			str[7 - i] = 0;
		else if (value % 2 != 0)
			str[7 - i] = 1;
		i++;
	}
	str[8] = '\0';
	if (str == NULL)
		return (0);
	return (str);
}

int	byte_ascii(int *numbers)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		result += numbers[7 - i] * ft_iterative_power(2, i);
		i++;
	}
	return (result);
}
