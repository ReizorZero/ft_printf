/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:31:23 by rzero             #+#    #+#             */
/*   Updated: 2019/07/12 19:51:41 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ret_value_f(t_flag *f, int l)
{
	if (f->precision == 0 && f->w_v > l)
		return (f->w_v);
	else if (f->precision == 0 && f->w_v <= l)
		return (l);
	else if (f->precision == 1 && f->width == 1)
	{
		if (f->p_v < l && f->w_v > l)
			return (f->w_v);
		else if (f->p_v >= l && f->w_v <= l)
			return (l);
		else if (f->p_v < l && f->w_v <= l)
			return (l);
	}
	if (f->precision == 1 && f->width == 0)
		return (l);
	return (f->w_v);
}

static int		o(t_flag *f, int l, long double d, char *ns)
{
	if (f->precision == 1 && f->p_v == 0 &&
	d == 0 && f->w_v == 0 && f->plus == 0)
	{
		ft_putstr("");
		free(ns);
		return (0);
	}
	else if (f->precision == 1 && f->p_v == 0 &&
	d == 0 && f->plus == 1 && f->w_v > 0)
		ft_putstr("+");
	else if (f->precision == 1 && f->p_v == 0 && d == 0 && f->w_v > 0)
		ft_putstr(" ");
	else
		ft_putstr(ns);
	print_width_after(f, l);
	free(ns);
	return (ret_value_f(f, l));
}

long double		parameter_value_f(t_flag *f, va_list vl)
{
	long double d;

	if (f->c_l == 1)
		d = (long)va_arg(vl, long double);
	else
		d = va_arg(vl, double);
	return (d);
}

int				print_f(va_list vl, t_flag *f)
{
	long double		d;
	char			*ns;
	int				l;

	d = parameter_value_f(f, vl);
	ns = ft_itoa_long_double(d, f, 0);
	l = ft_strlen(ns);
	ns = operate_precision_f(f, l, ns);
	ns = add_format_f(f, l, d, ns);
	ns = add_sign_f(f, d, ns);
	l = ft_strlen(ns);
	print_width_before(f, l);
	print_zero_f(f, l, d);
	return (o(f, l, d, ns));
}
