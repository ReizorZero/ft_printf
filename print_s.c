/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:12:27 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:41:27 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ret_value(t_flag *f, int l)
{
	if (f->precision == 1 && f->p_v == 0)
		return (f->w_v);
	else if (f->precision == 0 && f->w_v > l)
		return (f->w_v);
	else if (f->precision == 0 && f->w_v <= l)
		return (l);
	else if (f->precision == 1 && f->width == 1)
	{
		if (f->p_v < l && f->w_v > l)
			return (f->w_v);
		else if (f->p_v >= l && f->w_v <= l)
			return (l);
	}
	if (f->precision == 1 && f->width == 0)
		return ((f->p_v < l) ? f->p_v : l);
	return (f->w_v);
}

static void	print_width_before_s(t_flag *f, int l)
{
	int t;

	if (f->w_v > l && f->minus == 0)
	{
		t = f->w_v - l;
		while (t--)
			ft_putchar(' ');
	}
}

static void	print_width_after_s(t_flag *f, int l)
{
	int t;

	if (f->w_v > l && f->minus == 1)
	{
		t = f->w_v - l;
		while (t--)
			ft_putchar(' ');
	}
}

int			print_s(va_list vl, t_flag *f)
{
	char	*ns;
	int		l;

	ns = va_arg(vl, char*);
	if (ns == NULL)
		ns = "(null)";
	if (f->precision == 1)
	{
		ns = ft_strsub(ns, 0, (size_t)f->p_v);
		free(ns);
	}
	l = ft_strlen(ns);
	print_width_before_s(f, l);
	ft_putstr(ns);
	print_width_after_s(f, l);
	return (ret_value(f, l));
}
