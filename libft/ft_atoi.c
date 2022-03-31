/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:06:53 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/17 10:17:33 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	space(int c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			signe;
	long int	num;

	num = 0;
	signe = 1;
	while (space(*str))
		str++;
	while ((*str == '+' || *str == '-') && str)
	{
		if (*str == '-')
			signe *= -1;
		str ++;
		break ;
	}
	while (ft_isdigit(*str) && str)
	{
		num = (num * 10) + (*str - '0');
		str ++;
	}
	return (num * signe);
}
