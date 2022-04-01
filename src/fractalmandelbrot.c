/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/31 13:14:21 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_calculatemandel(t_data *img)
{
	double	Z_re;
	double	Z_im;
	double	Z_im2;
	int		maxitera;
	int		isInside;
	int		n;

    Z_re = img->c_re;
	Z_im = img->c_im;
    isInside = 1;
   	n = 0;
	maxitera = 50;
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
	return (isInside);
}
void	ft_fractolmandel(void *mlx, void *mlx_win, t_data *img)
{
	//area a pintar
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm + (MaxRe-MinRe) * ((img->size_x) / (img->size_y)); 
	
	int y;
	int	x;
	
	y = 0;
	while ( y < img->size_y)
	{
	    img->c_im = MaxIm - y * (MaxIm - MinIm) / (img->size_y - 1);
		x = 0;
		while (x < img->size_x)
		{
			img->c_re = MinRe + x * (MaxRe - MinRe) / (img->size_x - 1);
	        if(ft_calculatemandel(img))
			{
				my_mlx_pixel_put(img, x, y, 0x00FF7722);
		   	}
			x ++;
		}
		y ++;
	}
mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
