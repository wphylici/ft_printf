/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 07:00:23 by wphylici          #+#    #+#             */
/*   Updated: 2020/08/26 19:22:48 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_string(t_printf *elements, va_list argsptr)
{
	int		len;
	char	*str;

	str = va_arg(argsptr, char *);
	if (str == NULL || str == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (elements->precision < 0)
		elements->indicator_precision = -1;
	if (elements->flags == '-' || elements->width < 0)
		flag_minus_s(str, elements, len);
	else if (elements->indicator_precision != -1)
		precision_and_width_s(str, elements, len);
	else
		only_width_s(str, elements, len);
}

void	flag_minus_s(char *str, t_printf *elements, int len)
{
	int t;

	t = 0;
	if (elements->width < 0)
		elements->width *= (-1);
	if (elements->indicator_precision == -1)
	{
		elements->length += ft_putstr_fd(str, 1);
		elements->length += ft_putchar_len(' ', elements->width - len);
	}
	else if (elements->width != 0)
	{
		t = elements->precision < len ? elements->precision : len;
		elements->length += write(1, str, t);
		elements->length += ft_putchar_len(' ', elements->width - t);
	}
	else
	{
		t = elements->precision < len ? elements->precision : len;
		elements->length += write(1, str, t);
	}
}

void	precision_and_width_s(char *str, t_printf *elements, int len)
{
	int t;

	t = 0;
	if (elements->width != 0)
	{
		t = elements->precision < len ? elements->precision : len;
		elements->length += ft_putchar_len(' ', elements->width - t);
		elements->length += write(1, str, t);
	}
	else
	{
		t = elements->precision < len ? elements->precision : len;
		elements->length += write(1, str, t);
	}
}

void	only_width_s(char *str, t_printf *elements, int len)
{
	elements->length += ft_putchar_len(' ', elements->width - len);
	elements->length += ft_putstr_fd(str, 1);
}
