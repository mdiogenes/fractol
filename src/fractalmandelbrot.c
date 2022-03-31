/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/31 11:51:59 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_fractolmandel(void *mlx, void *mlx_win, t_data *img)
{
	//area a pintar
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm + (MaxRe-MinRe) * ((img->size_x) / (img->size_y)); 
	double Re_factor; 
	double Im_factor;
	//numero complex equivalen a y i x	
	double c_im;
	double c_re;
	
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;


	int MaxIterations;
	int n;
	int y;
	int	x;
	int isInside;
	int size_x;

	//per calcular numero comlex a y i x
	Re_factor = (MaxRe - MinRe) / (img->size_x - 1);
	Im_factor = (MaxIm - MinIm) / (img->size_y - 1);
	
	MaxIterations = 50;
	size_x = (*img).size_y;
	//ft_putnbr_fd(MaxIm,1);
	y = 0;
	while ( y < img->size_y)
	{
	    c_im = MaxIm - y * Im_factor;
		x = 0;
		while (x < img->size_x)
		{
	        c_re = MinRe + x * Re_factor;
        	Z_re = c_re;
			Z_im = c_im;
    	    isInside = 1;
    	    n = 0;
			while (n < MaxIterations)
	        {
	            Z_re2 = Z_re * Z_re; 
				Z_im2 = Z_im * Z_im;
				        	
            	Z_im = 2 * Z_re * Z_im + c_im;
        	    Z_re = Z_re2 - Z_im2 + c_re;
				
				if(Z_re2 + Z_im2 > 4)
     	      	{	
        	        isInside = 0;
        	        break;
        	    }
            	//Z_im = 2 * Z_re * Z_im + c_im;
        	    //Z_re = Z_re2 - Z_im2 + c_re;
				n ++;
    	    }
        	if(isInside)
			{
				my_mlx_pixel_put(img, x, y, 0x00FF7722);
		   	}
			x ++;
		}
		y ++;
	}
mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
