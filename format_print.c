/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:29:39 by rzero             #+#    #+#             */
/*   Updated: 2019/06/22 20:34:23 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_before(t_flag *f, int l)
{
	int t;

	if (f->w_v > l && f->minus == 0 && f->zero == 0)
	{
		if (f->p_v >= l)
			t = f->w_v - f->p_v;
		else
			t = f->w_v - l;
		while (t--)
			ft_putchar(' ');
	}
}

void	print_width_after(t_flag *f, int l)
{
	int t;

	if (f->w_v > l && f->minus == 1)
	{
		if (f->p_v >= l)
			t = f->w_v - f->p_v;
		else
			t = f->w_v - l;
		while (t--)
			ft_putchar(' ');
	}
}
