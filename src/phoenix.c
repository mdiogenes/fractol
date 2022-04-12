/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:43:35 by msoler-e          #+#    #+#             */
/*   Updated: 2022/04/12 12:43:52 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	phoenix(t_3d *d, t_cnb z, t_cnb c, int *i)
{
	double	n;
	t_cnb	t;

	n = z.real * z.real + z.imag * z.imag;
	t = (t_cnb) {.real = 0, .imag = 0};
	while (++(*i) < d->max && n < 4)
	{
		z.imag = 2 * fabs(z.imag * z.real) + c.imag;
		z.real = t.real - t.imag - c.real;
		t.real = z.real * z.real;
		t.imag = z.imag * z.imag;
		n = t.real + t.imag;
	}
typedef struct		s_cnb
{
	double			real;
	double			imag;
}					t_cnb;

/*}
