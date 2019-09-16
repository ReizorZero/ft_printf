/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:11:36 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 16:11:39 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_len(t_flag *f)
{
	f->n_h = 0;
	f->n_l = 0;
	f->n_c_l = 0;
}

void		operate_flag(t_flag *f)
{
	if (f->space == 1 && f->plus == 1)
		f->space = 0;
	if (f->zero == 1 && f->minus == 1)
		f->zero = 0;
}

void		set_flag_values(t_flag *f)
{
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->space = 0;
	f->zero = 0;
	f->width = 0;
	f->w_v = 0;
	f->precision = 0;
	f->p_v = 0;
	f->c = 0;
	f->f = 0;
	f->i = 0;
	f->o = 0;
	f->p = 0;
	f->s = 0;
	f->u = 0;
	f->x = 0;
	f->c_x = 0;
	f->h = 0;
	f->l = 0;
	f->c_l = 0;
	f->hh = 0;
	f->ll = 0;
	set_len(f);
}
