/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:10:21 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 08:15:31 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_char(t_printf *elements, va_list argsptr)
{
	char c;

	c = va_arg(argsptr, int);
	if (elements->width != 0)
	{
		if (elements->flags == '-')
		{
			if (elements->width < 0)
				elements->width *= (-1);
			elements->length += write(1, &c, 1);
			elements->length += ft_putchar_len(' ', elements->width - 1);
		}
		else if (elements->width > 0)
		{
			elements->length += ft_putchar_len(' ', elements->width - 1);
			elements->length += write(1, &c, 1);
		}
	}
	else
		elements->length += write(1, &c, 1);
}

void	print_persent(t_printf *elements)
{
	if (elements->flags == '-')
	{
		elements->length += ft_putchar_len('%', 1);
		elements->length += ft_putchar_len(' ', elements->width - 1);
	}
	else if (elements->flags == '0')
	{
		elements->length += ft_putchar_len('0', elements->width - 1);
		elements->length += ft_putchar_len('%', 1);
	}
	else
	{
		elements->length += ft_putchar_len(' ', elements->width - 1);
		elements->length += ft_putchar_len('%', 1);
	}
}
