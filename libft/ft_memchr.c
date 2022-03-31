/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:00:39 by msoler-e          #+#    #+#             */
/*   Updated: 2022/01/26 09:51:16 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	x;
	char	*st;

	x = 0;
	st = (void *) str;
	while (x < n)
	{
		if (((unsigned char *)st)[x] == (unsigned char) c)
			return (&st[x]);
		x ++;
	}
	return (0);
}
