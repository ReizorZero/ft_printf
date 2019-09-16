/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:12:14 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:35:20 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width_before_p(t_flag *f, int l)
{
	if (f->w_v > l && f->minus == 0)
	{
		l = f->w_v - l;
		while (l--)
			ft_putchar(' ');
	}
}

static void	print_width_after_p(t_flag *f, int l)
{
	if (f->w_v > l && f->minus == 1)
	{
		l = f->w_v - l;
		while (l--)
			ft_putchar(' ');
	}
}

int			print_p(va_list vl, t_flag *f)
{
	unsigned long int	p;
	char				*ns;
	int					l;
	int					printed;
	char				*s;

	p = va_arg(vl, unsigned long int);
	ns = ft_itoa_long_base(p, 16);
	s = ns;
	ns = ft_strjoin("0x", s);
	free(s);
	l = ft_strlen(ns);
	printed = l;
	print_width_before_p(f, l);
	ft_putstr(ns);
	print_width_after_p(f, l);
	free(ns);
	return ((f->w_v > l) ? f->w_v : printed);
}
