/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:13:48 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 08:16:01 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	init_struct(t_printf *elements)
{
	elements->flags = 0;
	elements->width = 0;
	elements->precision = 0;
	elements->type = 0;
	elements->indicator_precision = 0;
}

void	parser(const char **str, t_printf *elements, va_list argsptr)
{
	init_struct(elements);
	check_flags(str, elements);
	check_width(str, elements, argsptr);
	check_precision(str, elements, argsptr);
	check_type(str, elements);
}

int		processing(const char **str, t_printf *elements, va_list argsptr)
{
	parser(str, elements, argsptr);
	if (elements->type == 'c')
		print_char(elements, argsptr);
	else if (elements->type == 's')
		print_string(elements, argsptr);
	else if (ft_strchr("di", elements->type))
		print_number_d_i(elements, argsptr);
	else if (ft_strchr("uxX", elements->type))
		print_number_u_x(elements, argsptr);
	else if (elements->type == 'p')
		print_number_p(elements, argsptr);
	else if (elements->type == '%')
		print_persent(elements);
	else
		return (-1);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		argptr;
	t_printf	*elements;

	if (!(elements = (t_printf*)malloc((sizeof(t_printf)))))
		return (-1);
	elements->length = 0;
	va_start(argptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (processing(&str, elements, argptr) == -1)
				break ;
		}
		else
		{
			elements->length += write(1, str, 1);
			str++;
		}
	}
	free(elements);
	va_end(argptr);
	return (elements->length);
}
