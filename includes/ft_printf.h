/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:14:33 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 08:24:45 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_printf
{
	char		flags;
	int			width;
	int			precision;
	char		type;
	int			length;
	int			indicator_width;
	int			indicator_precision;
	int			indicator_percent;
}				t_printf;

int				ft_printf(const char *str, ...);
void			check_flags(const char **str, t_printf *elements);
void			check_width(const char **str, t_printf *elements,
												va_list argsptr);
void			check_precision(const char **str, t_printf *elements,
													va_list argsptr);
void			check_type(const char **str, t_printf *elements);
void			print_char(t_printf *elements, va_list argsptr);
void			print_string(t_printf *elements, va_list argsptr);
void			flag_minus_s(char *str, t_printf *elements, int len);
void			precision_and_width_s(char *str, t_printf *elements, int len);
void			only_width_s(char *str, t_printf *elements, int len);
void			print_persent(t_printf *elements);
void			print_number_d_i(t_printf *elements, va_list argsptr);
void			flag_minus_d_i(int number, t_printf *elements, int len);
void			precision_and_width_d_i(int number, t_printf *elements,
															int len);
void			flag_zero_d_i(int number, t_printf *elements, int len);
void			only_width_d_i(int number, t_printf *elements, int len);
void			print_number_u_x(t_printf *elements, va_list argsptr);
void			flag_minus_u_x(unsigned int number, t_printf *elements,
															int len);
void			precision_and_width_u_x(unsigned int number, t_printf
												*elements, int len);
void			flag_zero_u_x(unsigned int number, t_printf *elements,
															int len);
void			only_width_u_x(unsigned int number, t_printf *elements,
															int len);
void			print_number_p(t_printf *elements, va_list argsptr);
void			flag_minus_p(size_t number, t_printf *elements, int len);
void			precision_and_width_p(size_t number, t_printf *elements,
																int len);
void			flag_zero_p(size_t number, t_printf *elements, int len);
void			only_width_p(size_t number, t_printf *elements, int len);
int				ft_numlen(long long n, t_printf *elements);
int				ft_strlen(char *str);
char			*ft_strchr(const char *s, int c);
int				ft_putstr_fd(char *str, int fd);
int				ft_putchar_len(char c, int size);
int				ft_putnbr_fd(long long n, int fd, t_printf *elements);
#endif
