/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractaljulia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:52:20 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 15:40:17 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	ft_mouse_julia(t_data *tot, int x, int y)
{
	if (tot->freeze_julia == 1 || tot->freeze_julia == 0)
		mlx_loop_hook(tot->mlx, ft_mouse_julia, tot);
	mlx_mouse_get_pos(tot->mlx_win, &x, &y);
	tot->crejulia = tot->minre + x * (tot->maxre - tot->minre)
		/ (tot->sx - 1);
	tot->cimjulia = tot->maxim - y * (tot->maxim - tot->minim)
		/ (tot->sy - 1);
	tot->freeze_julia = 1;
	ft_fractaljulia(tot);
	return (0);
}

int	ft_calculatejulia(t_data *tot)
{
	double	z_re;
	double	z_im;
	double	old_re;
	double	old_im;
	int		n;

	z_re = tot->c_re;
	z_im = tot->c_im;
	n = 0;
	while (n < tot->maxitera)
	{
		old_re = z_re;
		old_im = z_im;
		z_re = old_re * old_re - old_im * old_im + tot->crejulia;
		z_im = 2 * old_re * old_im + tot->cimjulia;
		if ((z_re * z_re) + (z_im * z_im) > 2)
			break ;
		n ++;
	}
	return (ft_calculate_color_crazy(n, tot));
}

void	ft_fractaljulia(t_data *tot)
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
			my_mlx_pixel_put(tot, x, y, ft_calculatejulia(tot));
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(tot->mlx, tot->mlx_win, tot->img, 0, 0);
	mlx_hook(tot->mlx_win, 4, 1L << 2, ft_mouse_handler, tot);
	mlx_hook(tot->mlx_win, 2, 1L << 0, ft_hook, tot);
	mlx_loop(tot->mlx);
}
