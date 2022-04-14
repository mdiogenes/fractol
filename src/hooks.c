/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:48:45 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 11:43:52 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	ft_move(int keycode, t_data *tot)
{
	if (keycode == 123)
	{
		tot->minre = tot->minre + (0.1 * tot->zoom);
		tot->maxre = tot->maxre + (0.1 * tot->zoom);
	}
	if (keycode == 124)
	{
		tot->minre = tot->minre - (0.1 * tot->zoom);
		tot->maxre = tot->maxre - (0.1 * tot->zoom);
	}
	if (keycode == 126)
	{
		tot->minim = tot->minim - (0.1 * tot->zoom);
		tot->maxim = tot->maxim - (0.1 * tot->zoom);
	}
	if (keycode == 125)
	{
		tot->minim = tot->minim + (0.1 * tot->zoom);
		tot->maxim = tot->maxim + (0.1 * tot->zoom);
	}
}

void	ft_itera(int keycode, t_data *tot)
{
	if (keycode == 69)
		tot->maxitera = tot->maxitera + 10;
	if (keycode == 78)
		tot->maxitera = tot->maxitera - 10;
}

int	ft_hook(int keycode, t_data *tot)
{
	if (keycode == 53)
		ft_error("\n", 1, tot);
	if ((keycode == 69) || (keycode == 78))
		ft_itera(keycode, tot);
	if (keycode == 18)
	{
		tot->blue = 0;
		tot->red = 1;
		tot->green = 0;
	}	
	if (keycode == 19)
		ft_blue(tot);
	if (keycode == 20)
		ft_green(tot);
	if ((keycode >= 123) && (keycode <= 126))
		ft_move(keycode, tot);
	if (tot->fractal == 2)
		ft_fractaljulia(tot);
	if (tot->fractal == 3)
		ft_fractolburnship(tot);
	ft_fractolmandel(tot);
	return (0);
}

void	ft_loop_zoom(t_data *tot, int mouscode)
{
	if (mouscode == 4)
	{
		if (tot->zoom > 1)
			tot->zoom = 1;
		else
			tot->zoom = tot->zoom - 0.01;
	}
	if (mouscode == 5)
	{
		if (tot->zoom < 1)
			tot->zoom = 1;
		else
			tot->zoom = tot->zoom + 0.01;
	}
	if (tot->fractal == 2)
		ft_fractaljulia(tot);
	if (tot->fractal == 3)
		ft_fractolburnship(tot);
	if (tot->fractal == 1)
		ft_fractolmandel(tot);
}

int	ft_mouse_handler(int mouscode, int x, int y, t_data *tot)
{
	double	c_im;
	double	c_re;
	double	centim;
	double	centre;

	if (tot->fractal == 2 && mouscode == 1 && tot->freeze_julia == 0)
		ft_mouse_julia(tot, x, y);
	if (mouscode != 1)
	{
		c_im = tot->maxim - y * (tot->maxim - tot->minim) / (tot->size_y - 1);
		c_re = tot->minre + x * (tot->maxre - tot->minre) / (tot->size_x - 1);
		tot->maxre = tot->maxre * tot->zoom;
		tot->minre = tot->minre * tot->zoom;
		tot->minim = tot->minim * tot->zoom;
		tot->maxim = tot->minim + (tot->maxre - tot->minre)
			* ((tot->size_x) / (tot->size_y));
		centre = (tot->maxre - tot->minre) / 2;
		centim = (tot->maxim - tot->minim) / 2;
		tot->minre = c_re - centre;
		tot->maxre = c_re + centre;
		tot->maxim = c_im + centim;
		tot->minim = c_im - centim;
		ft_loop_zoom(tot, mouscode);
	}
	return (0);
}
