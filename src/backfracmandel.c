/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:48 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/31 09:13:47 by msoler-e         ###   ########.fr       */
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
	int		i;
	int		j;

	i = 0;
	while ( i < 1920)
	{
		j = 0;
		while ( j < 1080)
		{
			//mlx_pixel_put(mlx, mlx_win, i, j, 0x00117722);
			my_mlx_pixel_put(img, i, j, 0x00117722);
			j ++;
		}
		i++;
	}

	//draw_line(&img, 640, 360, 0, 0, 0xFFFFFF);
	//	my_mlx_pixel_put(&img, 50, 50, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
