/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/06 15:21:22 by msoler-e         ###   ########.fr       */
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

int	ft_close(int keycode, t_data *tot)
{
//	(void)mlx;
	(void)keycode;
	mlx_destroy_window(tot->mlx, tot->mlx_win);
	printf("Adeu Andreu!\n");
	return (0);	
}

int main (int argc, char **argv)
{
	int		size_x;
	t_data	tot;
	
	if (argc !=2)
		menu();	
	tot.size_x = 1920;
	tot.size_y = 1080;
	size_x = tot.size_x;
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
	mlx_hook(tot.mlx_win, 2, 1L<<0, ft_close, &tot);
	//mlx_key_hook(tot.mlx_win, key_hook, &tot.mlx);
	mlx_loop(tot.mlx);
}
