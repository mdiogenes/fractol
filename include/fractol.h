/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:31:18 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/12 12:41:07 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <signal.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
	double	c_im;
	double	c_re;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	int		maxitera;
	int		red;
	int		green;
	int		blue;
	int		trans;
	double	zoom;
	double	crejulia;
	double	cimjulia;
	int		fractal;
}	t_data;
void	ft_error(char *cnt, int error);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_fractolmandel(t_data *tot);
void	ft_fractaljulia(t_data *tot);
void	ft_fractolmarsu(t_data *tot);
int		ft_hook(int keycode, t_data *tot);
int		ft_mouse_handler(int mouscode, int x, int y, t_data *tot);
int		ft_mouse_julia(t_data *tot, int x, int y);
int		ft_calculate_color(int n, t_data *tot);
int		ft_calculate_color_crazy(int n, t_data *tot);
void	ft_red(t_data *tot);
void	ft_blue(t_data *tot);
void	ft_green(t_data *tot);
#endif
