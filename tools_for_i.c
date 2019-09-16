/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:36:50 by rzero             #+#    #+#             */
/*   Updated: 2019/06/22 20:37:08 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_i(t_flag *f, int l, long long int i)
{
	int t;

	if (f->w_v > l && f->zero == 1)
	{
		if (i < 0)
		{
			ft_putchar('-');
			t = f->w_v - l - 1;
		}
		else if (i >= 0 && f->plus == 1)
		{
			ft_putchar('+');
			t = f->w_v - l - 1;
		}
		else if (i >= 0 && f->space == 1)
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

char	*add_format_i(t_flag *f, int l, long long int i, char *ns)
{
	char	*s;

	if (f->space == 1 && f->zero == 1 && i >= 0 && f->w_v <= l + 1)
	{
		s = ns;
		ns = ft_strjoin(" ", s);
		free(s);
	}
	if (f->w_v == l && f->zero == 1 && i < 0)
	{
		s = ns;
		ns = ft_strjoin("-", s);
		free(s);
	}
	return (ns);
}

char	*add_sign_i(t_flag *f, long long int i, char *ns)
{
	char	*s;

	if (i < 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin("-", s);
		free(s);
	}
	if (f->space == 1 && i >= 0 && f->zero == 0)
	{
		s = ns;
		ns = ft_strjoin(" ", s);
		free(s);
	}
	if (f->plus == 1 && i >= 0 && f->zero == 0)
	{
		s = ns;
		if (f->precision == 1 && f->p_v == 0 && i == 0)
			ns = ft_strjoin("+", "");
		else
			ns = ft_strjoin("+", s);
		free(s);
	}
	return (ns);
}

char	*operate_precision_i(t_flag *f, int l, char *ns)
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
