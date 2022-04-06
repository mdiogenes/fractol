/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/06 12:41:34 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_calculatemandel(t_data *img, int maxitera)
{
	double	Z_re;
	double	Z_im;
	double	Z_im2;
	int		isInside;
	int		n;

    Z_re = img->c_re;
	Z_im = img->c_im;
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
		Z_im = 2 * Z_re * Z_im + img->c_im;
		Z_re = (Z_re * Z_re) - Z_im2 + img->c_re;
		n ++;
	}
	color = ft_calculate_color(t_data *img, int maxitera);
	return (color);
}
void	ft_fractolmandel(void *mlx, void *mlx_win, t_data *img)
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
	int		n;
	int 	num;
	int		trans;
	double		factor;
	//factor es el que multipliquem el numero n de maxitera per tenir un color mapejat
	
	maxitera =50;
	y = 0;
	while ( y < img->size_y)
	{
	    img->c_im = MaxIm - y * (MaxIm - MinIm) / (img->size_y - 1);
		x = 0;
		while (x < img->size_x)
		{
			img->c_re = MinRe + x * (MaxRe - MinRe) / (img->size_x - 1);
			n = ft_calculatemandel(img, maxitera);
			
	        if(n == maxitera)
				my_mlx_pixel_put(img, x, y, 0);
	        if(n <= (maxitera / 2 -1) && (n >= 0))
			{
				//de negre a vermell
				factor = 255 / ((maxitera / 2) -1) ;
				num = n * factor;
				trans = 25;
				num = ((trans << 24) | (num << 16));
				my_mlx_pixel_put(img, x, y, num );
			}
	        if(n >= (maxitera / 2) -10 && (n < maxitera))
			{
				//vermell a blanc
				factor = 255 / (maxitera - 1);
				num = n * factor;
				trans = 50;
				num = ((trans << 24) | (255 << 16) | (num << 8) | (num)); 
				my_mlx_pixel_put(img, x, y, num);
			}
	 		x ++;
		}
		y ++;
	}
mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
