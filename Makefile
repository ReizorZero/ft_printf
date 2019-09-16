NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

HDRF = ft_printf.h

SRCF = ft_printf.c operate_format.c ft_isdigit.c ft_putchar.c printer.c ft_putstr.c ft_strlen.c ft_strsub.c ft_itoa_long_base.c ft_strjoin.c ft_strdup.c ft_itoa_long_base_cptl.c print_c.c print_s.c print_p.c print_i.c print_o.c print_u.c print_x.c print_c_x.c flag.c format_print.c tools_for_i.c print_f.c tools_for_f.c ft_itoa_long_double.c tools_for_parcing.c

OBJF = ft_printf.o operate_format.o ft_isdigit.o ft_putchar.o printer.o ft_putstr.o ft_strlen.o ft_strsub.o ft_itoa_long_base.o ft_strjoin.o ft_strdup.o ft_itoa_long_base_cptl.o print_c.o print_s.o print_p.o print_i.o print_o.o print_u.o print_x.o print_c_x.o flag.o format_print.o tools_for_i.o print_f.o tools_for_f.o ft_itoa_long_double.o tools_for_parcing.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRCF) -I $(HDRF)
	ar rc $(NAME) $(OBJF)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
