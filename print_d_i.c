/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:02:47 by wphylici          #+#    #+#             */
/*   Updated: 2020/08/26 19:27:39 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_number_d_i(t_printf *elements, va_list argsptr)
{
	int len;
	int	number;

	number = va_arg(argsptr, int);
	len = ft_numlen(number, elements);
	if (elements->flags == '-' || elements->width < 0)
		flag_minus_d_i(number, elements, len);
	else if (elements->indicator_precision != -1)
		precision_and_width_d_i(number, elements, len);
	else if (elements->flags == '0')
		flag_zero_d_i(number, elements, len);
	else
		only_width_d_i(number, elements, len);
}

void	flag_minus_d_i(int number, t_printf *elements, int len)
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
		ft_putnbr_fd(number, 1, elements);
		elements->length += ft_putchar_len(' ', elements->width - t - len);
	}
	else
	{
		t = (elements->precision >= len) ? (elements->precision - len + 1) : 0;
		elements->length += write(1, "-", 1);
		elements->length += ft_putchar_len('0', t);
		ft_putnbr_fd(number * (-1), 1, elements);
		elements->length += ft_putchar_len(' ', elements->width - t - len);
	}
}

void	precision_and_width_d_i(int number, t_printf *elements, int len)
{
	int t;

	t = 0;
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		t = (elements->precision > len) ? (elements->precision - len) : 0;
		elements->length += ft_putchar_len(' ', elements->width - t - len);
		elements->length += ft_putchar_len('0', t);
		ft_putnbr_fd(number, 1, elements);
	}
	else
	{
		t = (elements->precision >= len) ? (elements->precision - len + 1) : 0;
		elements->length += ft_putchar_len(' ', elements->width - t - len);
		elements->length += write(1, "-", 1);
		elements->length += ft_putchar_len('0', t);
		ft_putnbr_fd(number * (-1), 1, elements);
	}
}

void	flag_zero_d_i(int number, t_printf *elements, int len)
{
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		elements->length += ft_putchar_len('0', elements->width - len);
		ft_putnbr_fd(number, 1, elements);
	}
	else
	{
		elements->length += write(1, "-", 1);
		elements->length += ft_putchar_len('0', elements->width - len);
		ft_putnbr_fd(number * (-1), 1, elements);
	}
}

void	only_width_d_i(int number, t_printf *elements, int len)
{
	if (number == 0 && elements->indicator_precision == 1)
		elements->length += ft_putchar_len(' ', elements->width);
	else if (number >= 0)
	{
		elements->length += ft_putchar_len(' ', elements->width - len);
		ft_putnbr_fd(number, 1, elements);
	}
	else
	{
		elements->length += ft_putchar_len(' ', elements->width - len);
		elements->length += write(1, "-", 1);
		elements->length += ft_putnbr_fd(number * (-1), 1, elements);
	}
}
