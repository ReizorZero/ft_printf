/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:10:33 by rzero             #+#    #+#             */
/*   Updated: 2019/06/18 15:18:34 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	abc(int n)
{
	return (n > 0 ? n : -n);
}

char		*ft_itoa_long_base(long int n, unsigned int base)
{
	char		*tab;
	char		*s;
	int			l;
	long int	t;

	l = 0;
	t = n;
	tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	while (t /= base)
		l++;
	l = l + 1;
	s = (char*)malloc(sizeof(char) * (l + 1));
	if (!s)
		exit(1);
	s[l] = '\0';
	while (l > 0)
	{
		s[l - 1] = tab[abc(n % base)];
		n /= base;
		l--;
	}
	return (s);
}
