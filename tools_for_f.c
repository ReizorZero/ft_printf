/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:23:45 by rzero             #+#    #+#             */
/*   Updated: 2019/07/12 17:23:47 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_f(t_flag *f, int l, long double d)
{
	int t;

	if (f->w_v > l && f->zero == 1)
	{
		if (d < 0)
		{
			ft_putchar('-');
			t = f->w_v - l - 1;
		}
		else if (d >= 0 && f->plus == 1)
		{
			ft_putchar('+');
			t = f->w_v - l - 1;
		}
		else if (d >= 0 && f->space == 1)
		{
			ft_putchar(' ');
			t = f->w_v - l - 1;
		}
		else
			t = f->w_v - l;
		while (t--)
			ft_putchar('0');
	}
}

char	*add_format_f(t_flag *f, int l, long double d, char *ns)
{
	char	*s;

	if (f->space == 1 && f->zero == 1 && d >= 0 && f->w_v <= l + 1)
	{
		s = ns;
		ns = ft_strjoin(" ", s);
		free(s);
	}
	if (f->w_v == l && f->zero == 1 && d < 0)
	{
		s = ns;
		ns = ft_strjoin("-", s);
		free(s);
	}
	return (ns);
}

char	*add_sign_f(t_flag *f, long double d, char *ns)
{
	char	*s;

	if (d < 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin("-", s);
		free(s);
	}
	if (f->space == 1 && d >= 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin(" ", s);
		free(s);
	}
	if (f->plus == 1 && d >= 0 && f->zero == 0)
	{
		s = ns;
		if (f->precision == 1 && f->p_v == 0 && d == 0)
			ns = ft_strjoin("+", "");
		else
			ns = ft_strjoin("+", s);
		free(s);
	}
	return (ns);
}

char	*operate_precision_f(t_flag *f, int l, char *ns)
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
