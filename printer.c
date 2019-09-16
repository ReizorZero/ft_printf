/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:13:06 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:13:09 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(va_list vl, t_flag *f)
{
	if (f->c == 1)
		return (print_c(vl, f));
	else if (f->s == 1)
		return (print_s(vl, f));
	else if (f->p == 1)
		return (print_p(vl, f));
	else if (f->i == 1)
		return (print_i(vl, f));
	else if (f->o == 1)
		return (print_o(vl, f));
	else if (f->u == 1)
		return (print_u(vl, f));
	else if (f->x == 1)
		return (print_x(vl, f));
	else if (f->c_x == 1)
		return (print_c_x(vl, f));
	else if (f->f == 1)
		return (print_f(vl, f));
	return (0);
}
