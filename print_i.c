/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:11:53 by rzero             #+#    #+#             */
/*   Updated: 2019/07/12 17:21:01 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ret_value_i(t_flag *f, int l)
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

static int		o(t_flag *f, int l, long long int i, char *ns)
{
	if (f->precision == 1 && f->p_v == 0 &&
	i == 0 && f->w_v == 0 && f->plus == 0)
	{
		ft_putstr("");
		free(ns);
		return (0);
	}
	else if (f->precision == 1 && f->p_v == 0 &&
	i == 0 && f->plus == 1 && f->w_v > 0)
		ft_putstr("+");
	else if (f->precision == 1 && f->p_v == 0 && i == 0 && f->w_v > 0)
		ft_putstr(" ");
	else
		ft_putstr(ns);
	print_width_after(f, l);
	free(ns);
	return (ret_value_i(f, l));
}

long long int	parameter_value_i(t_flag *f, va_list vl)
{
	long long int i;

	if (f->ll == 1)
		i = (long long int)va_arg(vl, void*);
	else if (f->l == 1)
		i = (long int)va_arg(vl, void*);
	else if (f->hh == 1)
		i = (char)va_arg(vl, void*);
	else if (f->h == 1)
		i = (short int)va_arg(vl, void*);
	else
		i = (int)va_arg(vl, void*);
	return (i);
}

int				print_i(va_list vl, t_flag *f)
{
	long long int	i;
	char			*ns;
	int				l;

	i = parameter_value_i(f, vl);
	ns = ft_itoa_long_base(i, 10);
	l = ft_strlen(ns);
	ns = operate_precision_i(f, l, ns);
	ns = add_format_i(f, l, i, ns);
	ns = add_sign_i(f, i, ns);
	l = ft_strlen(ns);
	print_width_before(f, l);
	print_zero_i(f, l, i);
	return (o(f, l, i, ns));
}
