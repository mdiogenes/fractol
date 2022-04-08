/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/08 13:12:05 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

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
	tot->size_x = 1920;
	tot->size_y = 1080;
	tot->red = 1;
	tot->green = 0;
	tot->blue = 0;
	tot->maxitera = 150;
	tot->zoom = 1;
	tot->posx = 0;
	tot->posy = 0;
	tot->MinRe = -2.0;
	tot->MaxRe = 1.0;
	tot->MinIm = -1.2;
	//tot->MaxIm = 1.186;
	tot->MaxIm = tot->MinIm + (tot->MaxRe-tot->MinRe) * ((tot->size_x) / (tot->size_y));
}

int main (int argc, char **argv)
{
	t_data	tot;
	
	if (argc !=2)
		menu();	
	ft_init_data(&tot);
	tot.mlx = mlx_init();
	tot.mlx_win = mlx_new_window(tot.mlx, tot.size_x, tot.size_y, "Hello world!");
	tot.img = mlx_new_image(tot.mlx, tot.size_x, tot.size_y);
	tot.addr = mlx_get_data_addr(tot.img, &tot.bits_per_pixel, &tot.line_length, &tot.endian);
	//mandelbort = 1
	if (argv[1][0] == 49)
		ft_fractolmandel(&tot);

	
	/*	//julia = 2
	if (argv[1][0] == 50)
		ft_fractol(mlx, mlx_win, &img);
	//altres = 3
	if (argv[1][0] == 51)
		ft_fractol(mlx, mlx_win, &img);
*/
}
