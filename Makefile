# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphylici <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 18:19:13 by wphylici          #+#    #+#              #
#    Updated: 2020/07/27 13:29:13 by wphylici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c check_elements.c print_c_percent.c print_s.c 			\
print_d_i.c print_u_x.c print_p.c ft_printf_utils_1.c ft_printf_utils_2.c

HEADER := includes/ft_printf.h

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re:  fclean all
