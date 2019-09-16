/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:12:48 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 16:18:03 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ret_value_x(t_flag *f, int l)
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

static int				print_zero_prefix_x(t_flag *f, int l)
{
	int t;

	if (f->w_v <= l && f->zero == 1 && f->hash == 1)
	{
		ft_putstr("0x");
		l += 2;
	}
	if (f->w_v > l && f->zero == 1)
	{
		if (f->hash == 1)
		{
			ft_putstr("0x");
			t = f->w_v - l - 2;
		}
		else
			t = f->w_v - l;
		while (t--)
			ft_putchar('0');
	}
	return (l);
}

static int				o(t_flag *f, int l, unsigned long long int x, char *ns)
{
	if (f->precision == 1 && f->p_v == 0 && x == 0 && f->width == 0)
	{
		ft_putstr("");
		free(ns);
		return (0);
	}
	else if (f->precision == 1 && f->p_v == 0 && x == 0 && f->w_v > 0)
		ft_putstr(" ");
	else
		ft_putstr(ns);
	print_width_after(f, l);
	free(ns);
	return (ret_value_x(f, l));
}

unsigned long long int	parameter_value_x(t_flag *f, va_list vl)
{
	unsigned long long int	x;

	if (f->ll == 1)
		x = va_arg(vl, unsigned long long int);
	else if (f->l == 1)
		x = va_arg(vl, unsigned long int);
	else
		x = va_arg(vl, unsigned int);
	return (x);
}

int						print_x(va_list vl, t_flag *f)
{
	unsigned long long int	x;
	char					*ns;
	int						l;
	char					*s;

	x = parameter_value_x(f, vl);
	ns = ft_itoa_long_base(x, 16);
	l = ft_strlen(ns);
	ns = operate_precision_x(f, l, ns);
	if (f->hash == 1 && f->precision == 0 && x == 0)
		f->hash = 0;
	if (f->hash == 1 && x > 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin("0x", s);
		free(s);
	}
	l = ft_strlen(ns);
	print_width_before(f, l);
	l = print_zero_prefix_x(f, l);
	return (o(f, l, x, ns));
}
