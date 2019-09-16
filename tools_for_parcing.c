/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_parcing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:24:18 by rzero             #+#    #+#             */
/*   Updated: 2019/07/12 17:24:21 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		run_flags(int i, char *fr, t_flag *f)
{
	if (fr[i] == '#')
		f->hash = 1;
	else if (fr[i] == '+')
		f->plus = 1;
	else if (fr[i] == '-')
		f->minus = 1;
	else if (fr[i] == ' ')
		f->space = 1;
	else if (fr[i] == '0')
		f->zero = 1;
	return (i);
}

int		run_width(int i, char *fr, t_flag *f, va_list vl)
{
	while (fr[i] != '\0' && (ft_isdigit(fr[i]) || fr[i] == '*'))
	{
		f->width = 1;
		if (fr[i] == '*')
		{
			f->w_v = va_arg(vl, int);
			return (i + 1);
		}
		else if (f->w_v == 0)
			f->w_v = fr[i] - '0';
		else
			f->w_v = (f->w_v * 10) + fr[i] - '0';
		i++;
	}
	i--;
	return (i);
}

int		run_prec(int i, char *fr, t_flag *f, va_list vl)
{
	f->precision = 1;
	i++;
	while (fr[i] != '\0' && (ft_isdigit(fr[i]) || fr[i] == '*'))
	{
		if (fr[i] == '*')
		{
			f->p_v = va_arg(vl, int);
			return (i);
		}
		else if (f->p_v == 0)
			f->p_v = fr[i] - '0';
		else
			f->p_v = (f->p_v * 10) + fr[i] - '0';
		i++;
	}
	i--;
	return (i);
}

void	run_len(t_flag *f)
{
	if (f->n_l > 0 && f->n_l % 2 == 0)
		f->ll = 1;
	else if (f->n_l > 0 && f->n_l % 2 != 0)
		f->l = 1;
	if (f->n_h > 0 && f->n_h % 2 == 0)
		f->hh = 1;
	else if (f->n_h > 0 && f->n_h % 2 != 0)
		f->h = 1;
	if (f->n_c_l > 0)
		f->c_l = 1;
}

void	run_spec(int i, char *fr, t_flag *f)
{
	if (fr[i] == 'c')
		f->c = 1;
	else if (fr[i] == 's')
		f->s = 1;
	else if (fr[i] == 'p')
		f->p = 1;
	else if (fr[i] == 'i' || fr[i] == 'd' || fr[i] == 'D')
		f->i = 1;
	else if (fr[i] == 'o' || fr[i] == 'O')
		f->o = 1;
	else if (fr[i] == 'u' || fr[i] == 'U')
		f->u = 1;
	else if (fr[i] == 'x')
		f->x = 1;
	else if (fr[i] == 'X')
		f->c_x = 1;
	else if (fr[i] == 'f' || fr[i] == 'F')
		f->f = 1;
}
