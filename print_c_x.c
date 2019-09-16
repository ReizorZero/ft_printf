/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:36:13 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 17:36:16 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				print_zero_prefix_c_x(t_flag *f, int l)
{
	int t;

	if (f->w_v <= l && f->zero == 1 && f->hash == 1)
	{
		ft_putstr("0X");
		l += 2;
	}
	if (f->w_v > l && f->zero == 1)
	{
		if (f->hash == 1)
		{
			ft_putstr("0X");
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

char					*operate_precision_x(t_flag *f, int l, char *ns)
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
	return (ns);
}

unsigned long long int	parameter_value_c_x(t_flag *f, va_list vl)
{
	unsigned long long int	x;

	if (f->ll == 1)
		x = (unsigned long long int)va_arg(vl, void*);
	else if (f->l == 1)
		x = (unsigned long int)va_arg(vl, void*);
	else
		x = (unsigned int)va_arg(vl, void*);
	return (x);
}

int						print_c_x(va_list vl, t_flag *f)
{
	unsigned long long int	x;
	char					*ns;
	int						l;
	char					*s;

	x = parameter_value_c_x(f, vl);
	ns = ft_itoa_long_base_cptl(x, 16);
	l = ft_strlen(ns);
	ns = operate_precision_x(f, l, ns);
	if (f->hash == 1 && f->precision == 0 && x == 0)
		f->hash = 0;
	if (f->hash == 1 && x > 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin("0X", s);
		free(s);
	}
	l = ft_strlen(ns);
	print_width_before(f, l);
	l = print_zero_prefix_c_x(f, l);
	return (o(f, l, x, ns));
}
