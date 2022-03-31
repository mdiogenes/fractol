/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:08:27 by msoler-e          #+#    #+#             */
/*   Updated: 2022/01/25 15:37:36 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*copia(unsigned int start, size_t len, char *dst, const char *s)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i ++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
	{
		dst = (char *)malloc(sizeof(char));
		if (!dst)
			return (0);
		dst[0] = '\0';
		return (dst);
	}
	if (slen - start < len)
		len = slen - start;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	dst = copia(start, len, dst, s);
	return (dst);
}
