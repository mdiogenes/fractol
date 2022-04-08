/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/08 13:12:09 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_calculate_color(int n, t_data *tot)
{
	int	factor;
	int	trans;
	int	color;

	color = 0;
	if(n <= (tot->maxitera / 2 -1) && (n >= 0))
	{
		//de negre a vermell,verd o blau
		factor = 255 / ((tot->maxitera / 2) -1) ;
		color = n * factor;
		trans = 0;
		color = ((trans << 24) | ((color * tot->red) << 16) | ((color * tot->green) << 8) | (color * tot->blue));
	}
	if(n >= (tot->maxitera / 2)  && (n < tot->maxitera))
	{
		//vermell a blanc
		factor = 255 / (tot->maxitera - 1);
		color = n * factor;
		trans = 0;
		if (tot->red == 1)
			color = ((trans << 24) | (255<< 16) | (color << 8) | (color));
		if (tot->blue == 1)
			color = ((trans << 24) | (color<< 16) | (color << 8) | (255));
		if (tot->green == 1)
			color = ((trans << 24) | (color<< 16) | (255 << 8) | (color));
	}
	return (color);
}

int	ft_calculatemandel(t_data *tot)
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
	while (n < tot->maxitera)
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
	color = ft_calculate_color(n, tot);
	return (color);
}
void	ft_fractolmandel(t_data *tot)
{
	//double 	MaxIm = MinIm + (MaxRe-MinRe) * ((img->size_x) / (img->size_y)); 	
	int 	y;
	int		x;
	int 	color;
	//factor es el que multipliquem el numero n de maxitera per tenir un color mapejat
	y = 0;
	while ( y < tot->size_y)
	{
	    tot->c_im = tot->MaxIm - y * (tot->MaxIm - tot->MinIm) / (tot->size_y - 1);
		x = 0;
		while (x < tot->size_x)
		{
			tot->c_re = tot->MinRe + x * (tot->MaxRe - tot->MinRe) / (tot->size_x - 1);
			color = ft_calculatemandel(tot);
			my_mlx_pixel_put(tot, x, y, color);
	 		x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(tot->mlx, tot->mlx_win, tot->img, 0, 0);
	mlx_hook(tot->mlx_win, 4, 1L << 2, ft_mouse_handler, tot);
	mlx_hook(tot->mlx_win, 5, 1L << 3, ft_mouse_handler, tot);
	mlx_hook(tot->mlx_win, 2, 1L<<0, ft_hook, tot);
	mlx_loop(tot->mlx);
}
