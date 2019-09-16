/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:11:42 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:11:45 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list vl, t_flag *f)
{
	char	c;
	int		printed;

	c = va_arg(vl, int);
	printed = f->w_v;
	if (f->width == 1 && f->minus == 1)
	{
		ft_putchar(c);
		f->w_v--;
		while (f->w_v--)
			ft_putchar(' ');
		return (printed);
	}
	else if (f->width == 1 && f->minus == 0)
	{
		f->w_v--;
		while (f->w_v--)
			ft_putchar(' ');
		ft_putchar(c);
		return (printed);
	}
	else
		ft_putchar(c);
	return (1);
}
