/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/06 15:11:41 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_calculate_color(int maxitera, int n)
{
	int	color;
	int	factor;
	int	trans;
	int red;
	int  green;
	int	blue;

	red = 0;
	green = 0;
	blue = 1;
	color = 0;
	if(n <= (maxitera / 2 -1) && (n >= 0))
	{
		//de negre a vermell
		factor = 255 / ((maxitera / 2) -1) ;
		color = n * factor;
		trans = 50;
		color = ((trans << 24) | ((color*red) << 16) | ((color*green) << 8) | (color*blue));
	}
	if(n >= (maxitera / 2) -10 && (n < maxitera))
	{
		//vermell a blanc
		factor = 255 / (maxitera - 1);
		color = n * factor;
		trans = 50;
		if (red == 1)
			color = ((trans << 24) | (255<< 16) | (color << 8) | (color));
		if (blue == 1)
			color = ((trans << 24) | (color<< 16) | (color << 8) | (255));
		if (green == 1)
			color = ((trans << 24) | (color<< 16) | (255 << 8) | (color));
	}
	return (color);
}

int	ft_calculatemandel(t_data *tot, int maxitera)
{
	double	Z_re;
	double	Z_im;
	double	Z_im2;
	int		isInside;
	int		n;
	int		color;

    Z_re = tot->c_re;
	Z_im = tot->c_im;
    isInside = 1;
   	n = 0;
	while (n < maxitera)
	{
		Z_im2 = Z_im * Z_im;
		if((Z_re * Z_re) + Z_im2 > 4)
     	{
			isInside = 0;
			break;
		}
		Z_im = 2 * Z_re * Z_im + tot->c_im;
		Z_re = (Z_re * Z_re) - Z_im2 + tot->c_re;
		n ++;
	}
	color = ft_calculate_color(maxitera, n);
	return (color);
}
void	ft_fractolmandel(t_data *tot)
{
	//area a pintar
	double 	MinRe = -2.0;
	double 	MaxRe = 1.0; 
	double 	MinIm = -1.2;
	double	MaxIm = 1.186;
	//double 	MaxIm = MinIm + (MaxRe-MinRe) * ((img->size_x) / (img->size_y)); 
	int		maxitera;	
	int 	y;
	int		x;
	int 	color;
	//factor es el que multipliquem el numero n de maxitera per tenir un color mapejat
	
	maxitera =50;
	y = 0;
	while ( y < tot->size_y)
	{
	    tot->c_im = MaxIm - y * (MaxIm - MinIm) / (tot->size_y - 1);
		x = 0;
		while (x < tot->size_x)
		{
			tot->c_re = MinRe + x * (MaxRe - MinRe) / (tot->size_x - 1);
			color = ft_calculatemandel(tot, maxitera);
			my_mlx_pixel_put(tot, x, y, color);
	 		x ++;
		}
		y ++;
	}
mlx_put_image_to_window(tot->mlx, tot->mlx_win, tot->img, 0, 0);
}
