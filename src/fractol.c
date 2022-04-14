/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 15:15:00 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	textmenu(t_data *tot)
{
	ft_putstr_fd("\nMENU\n", 1);
	ft_putstr_fd("1-Mandelbrotn\n", 1);
	ft_putstr_fd("2-Julia\n", 1);
	ft_putstr_fd("3-Altres\n", 1);
	ft_error("\n", 2, tot);
}

void	ft_init_data(t_data *tot)
{
	tot->freeze_julia = 0;
	tot->fractal = 1;
	tot->crejulia = -0.7;
	tot->cimjulia = 0.27015;
	tot->sx = 1920;
	tot->sy = 1080;
	tot->red = 1;
	tot->freq = 0.3;
	tot->green = 0;
	tot->blue = 0;
	tot->maxitera = 50;
	tot->trans = 0;
	tot->zoom = 1;
	tot->minre = -2.0;
	tot->maxre = 1.0;
	tot->minim = -1.2;
	tot->maxim = tot->minim + (tot->maxre - tot->minre)
		* ((tot->sx) / (tot->sy));
}

void	menu(char **argv, t_data *tot)
{
	int	option;

	option = ft_atoi(argv[1]);
	if (option < 1 || option > 3)
		textmenu(tot);
	if (option == 1)
	{
		tot->fractal = 1;
		tot->maxre = 1.0;
		tot->maxim = 1.2;
		ft_fractolmandel(tot);
	}
	if (option == 2)
	{
		tot->maxre = 2.0;
		tot->fractal = 2;
		ft_fractaljulia(tot);
	}
	if (option == 3)
	{
		tot->maxre = 1.5;
		tot->minim = -1.0;
		tot->fractal = 3;
		ft_fractolburnship(tot);
	}
}

int	main(int argc, char **argv)
{
	t_data	tot;

	ft_init_data(&tot);
	tot.mlx = mlx_init();
	tot.mlx_win = mlx_new_window(tot.mlx, tot.sx,
			tot.sy, "fractol");
	tot.img = mlx_new_image(tot.mlx, tot.sx, tot.sy);
	tot.addr = mlx_get_data_addr(tot.img, &tot.bits_per_pixel,
			&tot.line_length, &tot.endian);
	if (argc != 2)
		textmenu(&tot);
	menu(argv, &tot);
}
