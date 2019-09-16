/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:12:04 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:26:05 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ret_value_o(t_flag *f, int l, char *ns)
{
	free(ns);
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

static int	r(t_flag *f, int l, unsigned long long int o, char *ns)
{
	if (f->precision == 1 && f->p_v == 0 &&
	o == 0 && f->width == 0 && f->hash == 1)
	{
		ft_putstr("0");
		free(ns);
		return (1);
	}
	else if (f->precision == 1 && f->p_v == 0 &&
	o == 0 && f->width > 0 && f->hash == 1)
		(f->minus == 1) ? ft_putstr("0 ") : ft_putstr(" 0");
	else if (f->precision == 1 && f->p_v == 0 && o == 0 && f->width == 0)
	{
		ft_putstr("");
		free(ns);
		return (0);
	}
	else if (f->precision == 1 && f->p_v == 0 && o == 0 && f->w_v > 0)
		ft_putstr(" ");
	else
		ft_putstr(ns);
	print_width_after(f, l);
	return (ret_value_o(f, l, ns));
}

static char	*p(t_flag *f, int l, unsigned long long int o, char *ns)
{
	char	*s;
	int		t;

	if (f->precision == 1 && f->zero == 1)
		f->zero = 0;
	if (f->precision == 1 && f->p_v > l)
	{
		t = f->p_v - l;
		while (t--)
		{
			s = ns;
			ns = ft_strjoin("0", s);
			free(s);
		}
	}
	if (f->hash == 1 && f->precision == 0 && o == 0)
		f->hash = 0;
	if (f->hash == 1 && f->p_v <= l)
	{
		s = ns;
		ns = ft_strjoin("0", ns);
		free(s);
	}
	return (ns);
}

int			print_o(va_list vl, t_flag *f)
{
	unsigned long long int	o;
	char					*ns;
	int						l;
	int						t;

	if (f->ll == 1)
		o = (unsigned long long int)va_arg(vl, void*);
	else if (f->l == 1)
		o = (unsigned long int)va_arg(vl, void*);
	else
		o = (unsigned int)va_arg(vl, void*);
	ns = ft_itoa_long_base(o, 8);
	l = ft_strlen(ns);
	ns = p(f, l, o, ns);
	l = ft_strlen(ns);
	print_width_before(f, l);
	if (f->w_v > l && f->zero == 1)
	{
		t = f->w_v - l;
		while (t--)
			ft_putchar('0');
	}
	return (r(f, l, o, ns));
}
