/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:12:37 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:42:07 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ret_value_u(t_flag *f, int l, char *ns)
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

unsigned long long int	parameter_value_u(t_flag *f, va_list vl)
{
	unsigned long long int	u;

	if (f->ll == 1)
		u = (unsigned long long int)va_arg(vl, void*);
	else if (f->l == 1)
		u = (unsigned long int)va_arg(vl, void*);
	else
		u = (unsigned int)va_arg(vl, void*);
	return (u);
}

static int				o(t_flag *f, int l, unsigned long long int u, char *ns)
{
	if (f->precision == 1 && f->p_v == 0 &&
	u == 0 && f->width == 0 && f->hash == 1)
	{
		ft_putstr("0");
		free(ns);
		return (1);
	}
	else if (f->precision == 1 && f->p_v == 0 &&
	u == 0 && f->width > 0 && f->hash == 1)
		(f->minus == 1) ? ft_putstr("0 ") : ft_putstr(" 0");
	else if (f->precision == 1 && f->p_v == 0 && u == 0 && f->width == 0)
	{
		ft_putstr("");
		free(ns);
		return (0);
	}
	else if (f->precision == 1 && f->p_v == 0 && u == 0 && f->w_v > 0)
		ft_putstr(" ");
	else
		ft_putstr(ns);
	print_width_after(f, l);
	return (ret_value_u(f, l, ns));
}

static char				*p(t_flag *f, int l, unsigned long long int u, char *ns)
{
	int		t;
	char	*s;

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
	if (f->hash == 1 && f->precision == 0 && u == 0)
		f->hash = 0;
	if (f->hash == 1 && f->p_v <= l)
	{
		s = ns;
		ns = ft_strjoin("0", ns);
		free(s);
	}
	return (ns);
}

int						print_u(va_list vl, t_flag *f)
{
	unsigned long long int	u;
	char					*ns;
	int						l;
	int						t;

	u = parameter_value_u(f, vl);
	ns = ft_itoa_long_base(u, 10);
	l = ft_strlen(ns);
	ns = p(f, l, u, ns);
	l = ft_strlen(ns);
	print_width_before(f, l);
	if (f->w_v > l && f->zero == 1)
	{
		t = f->w_v - l;
		while (t--)
			ft_putchar('0');
	}
	return (o(f, l, u, ns));
}
