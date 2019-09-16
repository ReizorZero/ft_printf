/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:11:27 by rzero             #+#    #+#             */
/*   Updated: 2019/06/22 20:36:15 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				run_percent(int i, t_flag *f)
{
	ft_putchar('\%');
	f->printed += 1;
	return (i);
}

static int		parse_format(t_flag *f, char *fr, int i, va_list vl)
{
	set_flag_values(f);
	while (fr[i] != '\0' && !FRMT(fr[i]) && !CFRMT(fr[i]) && !OFRMT(fr[i]))
	{
		if (ISFLG(fr[i]))
			i = run_flags(i, fr, f);
		else if (ft_isdigit(fr[i]) || fr[i] == '*')
			i = run_width(i, fr, f, vl);
		else if (fr[i] == '.')
			i = run_prec(i, fr, f, vl);
		else if (fr[i] == 'l')
			f->n_l++;
		else if (fr[i] == 'h')
			f->n_h++;
		else if (fr[i] == 'L')
			f->n_c_l++;
		else if (fr[i] == '%')
			return (run_percent(i, f));
		else
			return (i - 1);
		i++;
	}
	run_len(f);
	run_spec(i, fr, f);
	operate_flag(f);
	return (i);
}

static int		do_output(char *format, int i, int printed)
{
	ft_putchar(format[i]);
	return (printed + 1);
}

int				operate_format(char *format, va_list vl)
{
	t_flag		*f;
	int			i;
	int			printed;

	f = (t_flag*)malloc(sizeof(t_flag));
	if (!f)
		exit(1);
	i = 0;
	f->printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = parse_format(f, format, i + 1, vl);
			f->printed += printer(vl, f);
		}
		else
			f->printed = do_output(format, i, f->printed);
		i++;
	}
	printed = f->printed;
	free(f);
	return (printed);
}
