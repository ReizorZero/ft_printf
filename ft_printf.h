/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:10:59 by rzero             #+#    #+#             */
/*   Updated: 2019/06/22 21:37:41 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define ISFLG(y) ((y)=='#'||(y)=='+'||(y)=='-'||(y)==' '||(y)=='0')
# define FRMT(y) ((y)=='d'||(y)=='i'||(y)=='o'||(y)=='u'||(y)=='x'||(y)=='X')
# define CFRMT(y) ((y)=='D'||(y)=='C'||(y)=='O'||(y)=='U'||(y)=='F'||(y)=='S')
# define OFRMT(y) ((y)=='c'||(y)=='s'||(y)=='p'||(y)=='f')

typedef struct	s_flag
{
	int	space;
	int hash;
	int plus;
	int minus;
	int zero;
	int width;
	int w_v;
	int precision;
	int p_v;
	int c;
	int s;
	int p;
	int i;
	int o;
	int u;
	int x;
	int c_x;
	int f;
	int hh;
	int h;
	int ll;
	int	l;
	int c_l;
	int printed;
	int n_h;
	int n_l;
	int n_c_l;
}				t_flag;

int				ft_printf(const char *format, ...);
int				operate_format(char *format, va_list vl);
int				printer(va_list vl, t_flag *f);

int				run_flags(int i, char *fr, t_flag *f);
int				run_width(int i, char *fr, t_flag *f, va_list vl);
int				run_prec(int i, char *fr, t_flag *f, va_list vl);
void			run_len(t_flag *f);
void			run_spec(int i, char *fr, t_flag *f);
void			operate_flag(t_flag *f);
void			set_flag_values(t_flag *f);

void			print_width_before(t_flag *f, int l);
void			print_width_after(t_flag *f, int l);

int				print_c(va_list vl, t_flag *f);
int				print_s(va_list vl, t_flag *f);
int				print_p(va_list vl, t_flag *f);
int				print_i(va_list vl, t_flag *f);
int				print_o(va_list vl, t_flag *f);
int				print_u(va_list vl, t_flag *f);
int				print_x(va_list vl, t_flag *f);
int				print_c_x(va_list vl, t_flag *f);
int				print_f(va_list vl, t_flag *f);

void			print_zero_i(t_flag *f, int l, long long int i);
char			*add_format_i(t_flag *f, int l, long long int i, char *ns);
char			*add_sign_i(t_flag *f, long long int i, char *ns);
char			*operate_precision_i(t_flag *f, int l, char *ns);

void			print_zero_f(t_flag *f, int l, long double d);
char			*add_format_f(t_flag *f, int l, long double d, char *ns);
char			*add_sign_f(t_flag *f, long double d, char *ns);
char			*operate_precision_f(t_flag *f, int l, char *ns);

int				ret_value_x(t_flag *f, int l);
char			*operate_precision_x(t_flag *f, int l, char *ns);

char			*ft_itoa_long_base(long int n, unsigned int base);
char			*ft_itoa_long_base_cptl(long int n, unsigned int base);
char			*ft_itoa_long_double(long double n, t_flag *f, int temp);

int				ft_isdigit(int c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
