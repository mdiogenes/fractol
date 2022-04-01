/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:31:18 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/31 13:14:19 by msoler-e         ###   ########.fr       */
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

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
	double	c_im; //numeros complex imaginari equivalen a y
	double	c_re;
} t_data;

void	ft_error(char *cnt, int error);
void	ft_fractolmandel(void *mlx, void *mlx_win, t_data *img);
#endif
