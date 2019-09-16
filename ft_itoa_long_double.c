/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:31:43 by rzero             #+#    #+#             */
/*   Updated: 2019/07/12 19:31:46 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_len(char *s, int pr, int temp)
{
	char *t;

	pr = temp - (int)ft_strlen(s);
	while (pr > 0)
	{
		t = s;
		s = ft_strjoin(t, "0");
		free(t);
		pr--;
	}
	return (s);
}

char		*ft_itoa_long_double(long double n, t_flag *f, int temp)
{
	char		*fp;
	char		*s;
	long double	d;
	int			pr;
	char		*t;

	fp = ft_itoa_long_base((long long int)n, 10);
	d = n - (long long int)n;
	pr = (f->precision == 1) ? (f->p_v) : 6;
	temp = pr;
	while (pr-- > 0)
		d *= 10;
	s = ft_itoa_long_base((long long int)d, 10);
	t = fp;
	fp = ft_strjoin(t, ".");
	free(t);
	if ((int)ft_strlen(s) < temp)
		s = add_len(s, pr, temp);
	t = fp;
	fp = ft_strjoin(t, s);
	free(t);
	free(s);
	return (fp);
}
