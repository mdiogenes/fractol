/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:56 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/31 11:51:41 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/
/*int draw_line(void *win, int beginX, int beginY, int endX, int endY, int color)
{

	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels; 
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
	    my_mlx_pixel_put(win, pixelX, pixelY, color);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}
	return (0);
}
*/
/*void	ft_fractol(void *mlx, void *mlx_win, t_data *img)
{
	int		i;
	int		j;
	
	i = 0;
	while ( i < 100)
	{
		j = 0;
		while ( j < 100)
		{
			//my_mlx_pixel_put(img, i, j, 0x00FFFFFF);			
			j ++;
		}
		i++;
	}

	//draw_line(&img, 640, 360, 0, 0, 0xFFFFFF);
	//	my_mlx_pixel_put(&img, 50, 50, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
*/

void	menu(void)
{
		ft_putstr_fd("\nMENU\n", 1);
		ft_putstr_fd("1-Mandelbrotn\n", 1);
		ft_putstr_fd("2-Julia\n", 1);
		ft_putstr_fd("3-Altres\n", 1);
		ft_error("Error", 2);
}

int main (int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	size_x;
	
	if (argc !=2)
		menu();	
	img.size_x = 1920;
	img.size_y = 1080;
	size_x = img.size_x;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.size_x, img.size_y, "Hello world!");
	img.img = mlx_new_image(mlx, img.size_x, img.size_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//mandelbort = 1
	if (argv[1][0] == 49)
		ft_fractolmandel(mlx, mlx_win, &img);
/*	//julia = 2
	if (argv[1][0] == 50)
		ft_fractol(mlx, mlx_win, &img);
	//altres = 3
	if (argv[1][0] == 51)
		ft_fractol(mlx, mlx_win, &img);
*/
	mlx_loop(mlx);
}
