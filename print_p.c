/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:45:20 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 08:23:58 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_number_p(t_printf *elements, va_list argsptr)
{
	int 	len;
	size_t	number;

	number = va_arg(argsptr, size_t);
	len = ft_numlen(number, elements) + 2;
	if (elements->flags == '-' || elements->width < 0)
		flag_minus_p(number, elements, len);
	else if (elements->indicator_precision != -1)
		precision_and_width_p(number, elements, len);
	else if (elements->flags == '0')
		flag_zero_p(number, elements, len);
	else
		only_width_p(number, elements, len);
}

void	flag_minus_p(size_t number, t_printf *elements, int len)
{
	int t;

	t = 0;
	if (elements->width < 0)
		elements->width *= (-1);
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		t = (elements->precision > len) ? (elements->precision - len) : 0;
		elements->length += ft_putchar_len('0', t);
		elements->length += ft_putstr_fd("0x", 1);
		ft_putnbr_fd(number, 1, elements);
		elements->length += ft_putchar_len(' ', elements->width - t - len);
	}
}

void	precision_and_width_p(size_t number, t_printf *elements, int len)
{
	int t;

	t = 0;
	if (number == 0 && elements->indicator_precision == 1)
	{
		elements->length += ft_putchar_len(' ', elements->width - 2);
		elements->length += ft_putstr_fd("0x", 1);
	}
	else if (number >= 0)
	{
		t = (elements->precision > len) ? (elements->precision - len) : 0;
		elements->length += ft_putchar_len(' ', elements->width - t - len);
		elements->length += ft_putstr_fd("0x", 1);
		elements->length += ft_putchar_len('0', elements->precision -
															(len - 2));
		ft_putnbr_fd(number, 1, elements);
	}
}

void	flag_zero_p(size_t number, t_printf *elements, int len)
{
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		elements->length += ft_putchar_len('0', elements->width - len);
		elements->length += ft_putstr_fd("0x", 1);
		ft_putnbr_fd(number, 1, elements);
	}
}

void	only_width_p(size_t number, t_printf *elements, int len)
{
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		elements->length += ft_putchar_len(' ', elements->width - len);
		elements->length += ft_putstr_fd("0x", 1);
		ft_putnbr_fd(number, 1, elements);
	}
}
