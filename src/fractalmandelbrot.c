/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 14:50:26 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	ft_calculatemandel(t_data *tot)
{
	double	z_re;
	double	z_im;
	double	z_im2;
	int		isinside;
	int		n;

	z_re = tot->c_re;
	z_im = tot->c_im;
	isinside = 1;
	n = 0;
	while (n < tot->maxitera)
	{
		z_im2 = z_im * z_im;
		if ((z_re * z_re) + z_im2 > 4)
		{
			isinside = 0;
			break ;
		}
		z_im = 2 * z_re * z_im + tot->c_im;
		z_re = (z_re * z_re) - z_im2 + tot->c_re;
		n ++;
	}
	return (ft_calculate_color(n, tot));
}

void	ft_fractolmandel(t_data *tot)
{
	int	y;
	int	x;

	y = 0;
	while (y < tot->sy)
	{
		tot->c_im = tot->maxim - y * (tot->maxim - tot->minim)
			/ (tot->sy - 1);
		x = 0;
		while (x < tot->sx)
		{
			tot->c_re = tot->minre + x * (tot->maxre - tot->minre)
				/ (tot->sx - 1);
			my_mlx_pixel_put(tot, x, y, ft_calculatemandel(tot));
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
