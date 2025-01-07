/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeltahi <haeltahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:21 by haeltahi          #+#    #+#             */
/*   Updated: 2023/12/26 14:04:53 by haeltahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str[i] == '\0' || fd < 0)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

double	atoidbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
