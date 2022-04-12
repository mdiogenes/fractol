/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marsu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:53 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/12 10:04:48 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	ft_calculatemarsu(t_data *tot)
{
	double	z_re;
	double	z_im;
	double z_renou;
	double z_reant;
	double z_imant;
	double z_imnou;
	double c_im;
	double c_re;
	int	n;

	c_im = 0.5667;
	c_re = -0.5;	
	z_reant = 0;
	z_im = 1;
	n = 0;
	z_imant = 0;
	z_re = tot->c_re + tot->c_im;

	while ((n < tot->maxitera) && (((z_im * z_im) + (z_re *z_re)) < 4))
	{
		z_imnou = 2 * fabs(z_im * z_re) + c_im * z_imant;
		z_imant =  z_im;
		z_im = z_imnou;		
		z_renou = (z_re * z_re) + c_re + (c_im * z_reant);
		z_reant = z_re;
		z_re = z_renou;
	}
	return (ft_calculate_color(n, tot));
}

void	ft_fractolmarsu(t_data *tot)
{
	int	y;
	int	x;

	y = 0;
	while (y < tot->size_y)
	{
		tot->c_im = tot->maxim - y * (tot->maxim - tot->minim)
			/ (tot->size_y - 1);
		x = 0;
		while (x < tot->size_x)
		{
			tot->c_re = tot->minre + x * (tot->maxre - tot->minre)
				/ (tot->size_x - 1);
			my_mlx_pixel_put(tot, x, y, ft_calculatemarsu(tot));
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(tot->mlx, tot->mlx_win, tot->img, 0, 0);
	mlx_hook(tot->mlx_win, 4, 1L << 2, ft_mouse_handler, tot);
	mlx_hook(tot->mlx_win, 5, 1L << 3, ft_mouse_handler, tot);
	mlx_hook(tot->mlx_win, 2, 1L << 0, ft_hook, tot);
	mlx_loop(tot->mlx);
}
