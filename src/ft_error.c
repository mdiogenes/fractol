/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:59:19 by msoler-e          #+#    #+#             */
/*   Updated: 2022/03/29 12:23:42 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


void	ft_error(char *cnt, int error)
{
	if (error == 2)
	{		
		ft_putstr_fd("\n2_Error_Arguments\n", 1);
		ft_putstr_fd(cnt, 1);
	}
	if (error == 0)
	{
		ft_putstr_fd("\n0_Error_Malloc\n", 1);
		ft_putstr_fd(cnt, 1);
	}	
	if (error == 1)
	{
		ft_putstr_fd("1_Numeros_duplicats", 1);
		ft_putstr_fd(cnt, 1);
	}
	exit (error);
}
