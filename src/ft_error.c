/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:59:19 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/14 11:42:36 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_error(char *cnt, int error, t_data *tot)
{
	mlx_destroy_image(tot->mlx, tot->img);
	mlx_destroy_window(tot->mlx, tot->mlx_win);
	if (error == 2)
	{		
		ft_putstr_fd("\n2_Error_Arguments\n", 1);
		ft_putstr_fd(cnt, 1);
	}
	if (error == 0)
	{
		ft_putstr_fd("\n0_Malloc Error\n", 1);
		ft_putstr_fd(cnt, 1);
	}	
	if (error == 1)
	{
		ft_putstr_fd("! Adeu Andreu !", 1);
		ft_putstr_fd(cnt, 1);
	}
	exit (error);
}
