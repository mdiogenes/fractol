/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/12 12:36:10 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	menu(void)
{
	ft_putstr_fd("\nMENU\n", 1);
	ft_putstr_fd("1-Mandelbrotn\n", 1);
	ft_putstr_fd("2-Julia\n", 1);
	ft_putstr_fd("3-Altres\n", 1);
	ft_error("Error", 2);
}

void	ft_init_data(t_data *tot)
{
	tot->fractal = 1;
	tot->crejulia = -0.7;
	tot->cimjulia = 0.27015;
	tot->size_x = 1920;
	tot->size_y = 1080;
	tot->red = 1;
	tot->green = 0;
	tot->blue = 0;
	tot->maxitera = 75;
	tot->trans = 5;
	tot->zoom = 1;
	tot->minre = -2.0;
	tot->maxre = 1.0;
	tot->minim = -1.2;
	tot->maxim = tot->minim + (tot->maxre - tot->minre)
		* ((tot->size_x) / (tot->size_y));
}

int	main(int argc, char **argv)
{
	t_data	tot;

	if (argc != 2)
		menu();
	ft_init_data(&tot);
	tot.mlx = mlx_init();
	tot.mlx_win = mlx_new_window(tot.mlx, tot.size_x,
			tot.size_y, "Hello world!");
	tot.img = mlx_new_image(tot.mlx, tot.size_x, tot.size_y);
	tot.addr = mlx_get_data_addr(tot.img, &tot.bits_per_pixel,
			&tot.line_length, &tot.endian);
	if (argv[1][0] == 49)
		ft_fractolmandel(&tot);
	if (argv[1][0] == 50)
	{
		tot.maxre = 2.0;
		tot.fractal = 2;
		ft_fractaljulia(&tot);
	}	
	if (argv[1][0] == 51)
	{
		tot.fractal = 3;
		ft_fractolmarsu(&tot);
	}
}
