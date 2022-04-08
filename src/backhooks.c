/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:48:45 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/08 12:39:57 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_move(int keycode, t_data *tot)
{
	if (keycode == 123)
	{
		//scroll left
		tot->MinRe = tot->MinRe + (0.1 * tot->zoom);
		tot->MaxRe = tot->MaxRe + (0.1 * tot->zoom);
	}
	if (keycode == 124)
	{
		//scroll right
		tot->MinRe = tot->MinRe - (0.1 * tot->zoom);
		tot->MaxRe = tot->MaxRe - (0.1 * tot->zoom);
		}
	if (keycode == 126)
	{
		//scroll up
		tot->MinIm = tot->MinIm - (0.1 * tot->zoom);
		tot->MaxIm = tot->MaxIm - (0.1 * tot->zoom);
	}
	if (keycode == 125)
	{
		//scroll down
		tot->MinIm = tot->MinIm + (0.1 * tot->zoom);
		tot->MaxIm = tot->MaxIm + (0.1 * tot->zoom);
	}
}

int	ft_hook(int keycode, t_data *tot)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tot->mlx, tot->mlx_win);
		exit(0);
	}
	if (keycode == 18)
	{
		tot->red = 1;
		tot->blue = 0;
		tot->green = 0;
	}
	if (keycode == 19)
	{
		tot->red =0;
		tot->blue = 0;
		tot->green = 1;
	}
	if (keycode == 20)
	{
		tot->red = 0;
		tot->blue = 1;
		tot->green = 0;
	}
	if ((keycode >=123) && (keycode <=126))
		ft_move(keycode, tot);

	ft_fractolmandel(tot);
	return(0);
}
int ft_mouse_handler(int mouscode, int x, int y, t_data *tot)
{
	double	c_im;
	double	c_re;
	double	centim;
	double	centre;

	//calculem el centre
	
	centim = (tot->MaxRe - tot->MinRe) / 2;
	centre = (tot->MaxIm - tot->MinIm) / 2;	

	c_im = tot->MaxIm - y * (tot->MaxIm - tot->MinIm) / (tot->size_y - 1);
	c_re = tot->MinRe + x * (tot->MaxRe - tot->MinRe) / (tot->size_x - 1);	
	
//	if ((c_re - centre) > tot->MinRe)
		tot->MinRe = c_re - centre;
//	if ((c_re + centre) < tot->MaxRe)
		tot->MaxRe = c_re + centre;

//	if ((c_im + centim) < tot->MaxIm)
		tot->MaxIm = c_im + centim;
//	if ((c_im - centim) > tot->MinIm)
		tot->MinIm = c_im - centim;

	if (mouscode == 4)
	{
		//scrollup
		tot->zoom = tot->zoom - 0.1;
	}
	if (mouscode == 5)
	{
		//scrolldown
		tot->zoom = tot->zoom + 0.1;
	}

	printf("\nZoom%f", tot->zoom);
	printf("\nMAXRE%f", tot->MaxRe);
	printf("\nMINRE%f", tot->MinRe);
	printf("\nMinIm%f", tot->MinIm);
	printf("\nMaxIm%f", tot->MaxIm);
	printf("\n");
	//tot->MaxIm = tot->MaxIm * tot->zoom;
	tot->MaxRe = tot->MaxRe * tot->zoom;
	tot->MinRe = tot->MinRe * tot->zoom;
	tot->MinIm = tot->MinIm * tot->zoom;
	tot->MaxIm = tot->MinIm + (tot->MaxRe-tot->MinRe) * ((tot->size_x) / (tot->size_y));
	ft_fractolmandel(tot);
	return(0);
}
