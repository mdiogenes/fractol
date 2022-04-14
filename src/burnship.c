/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:30:35 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 11:24:51 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	ft_calculateburnship(t_data *tot)
{
	double	n;
	double	z_re;
	double	z_im;
	double	z2_re;
	double	z2_im;

	z_re = tot->c_re;
	z_im = tot->c_im;
	n = 0;
	z2_re = z_re * z_re;
	z2_im = z_im * z_im;
	while (n < tot->maxitera && (z2_im) + (z2_re) < 4)
	{
		z_im = fabs(z_re * z_im);
		z_im = z_im + z_im - tot->c_im;
		z_re = (z2_re) - (z2_im) + tot->c_re;
		z2_re = z_re * z_re;
		z2_im = z_im * z_im;
		n ++;
	}
	return (ft_calculate_color(n, tot));
}

void	ft_fractolburnship(t_data *tot)
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
			my_mlx_pixel_put(tot, x, y, ft_calculateburnship(tot));
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
