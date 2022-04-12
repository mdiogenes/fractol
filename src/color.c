/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:28:17 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/12 12:33:06 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_color_towhite(t_data *tot, int color)
{
	if (tot->red == 1)
		color = ((tot->trans << 24) | (255 << 16) | (color << 8) | color);
	if (tot->blue == 1)
		color = ((tot->trans << 24) | (color << 16) | (color << 8) | (255));
	if (tot->green == 1)
		color = ((tot->trans << 24) | (color << 16) | (255 << 8) | color);
	return (color);
}

void	ft_blue(t_data *tot)
{
	tot->blue = 1;
	tot->red = 0;
	tot->green = 0;
}

void	ft_green(t_data *tot)
{
	tot->blue = 0;
	tot->red = 0;
	tot->green = 1;
}

int	ft_calculate_color_crazy(int n, t_data *tot)
{
	int		color;
	double	frequency;

	color = 0;
	frequency = 0.3;
	tot->red = sin(frequency * n + 0) * 127 + 128;
	tot->green = sin(frequency * n + 2) * 127 + 128;
	tot->blue = sin(frequency * n + 4) * 127 + 128;
	color = ((tot->trans << 24)
			| (tot->red << 16) | (tot->green << 8) | (tot->blue));
	return (color);
}

int	ft_calculate_color(int n, t_data *tot)
{
	int	factor;
	int	color;

	color = 0;
	if (n <= (tot->maxitera / 2 - 1) && (n >= 0))
	{	
		factor = 255 / ((tot->maxitera / 2) - 1);
		color = n * factor;
		color = ((tot->trans << 24) | ((color * tot->red) << 16)
				| ((color * tot->green) << 8) | (color * tot->blue));
	}
	if (n >= (tot->maxitera / 2) && (n < tot->maxitera))
	{
		factor = 255 / (tot->maxitera - 1);
		color = n * factor;
		color = ft_color_towhite(tot, color);
	}
	return (color);
}
