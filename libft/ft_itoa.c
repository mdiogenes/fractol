/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:03:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/01/25 16:47:02 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	countdigits(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*cutdigits(char *resultat, int signe, int n, int digits)
{
	char	num;

	resultat[digits] = '\0';
	while (n > 0)
	{
		num = (n % 10) + '0';
		n = n / 10;
		resultat[digits - 1] = num;
		digits --;
	}
	if (signe)
		resultat[0] = '-';
	return (resultat);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		signe;
	char	*resultat;

	signe = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
	signe = 1;
	n = n * -1;
	}
	digits = countdigits(n) + signe;
	resultat = malloc(sizeof(char) * (digits + 1));
	if (!resultat)
		return (0);
	resultat = cutdigits(resultat, signe, n, digits);
	return (resultat);
}
