/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 01:18:13 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 13:39:02 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	check_flags(const char **str, t_printf *elements)
{
	if (**str == ' ')
	{
		elements->length += write(1, " ", 1);
		(*str)++;
	}
	if (**str == '0' || **str == '-')
	{
		elements->flags = **str;
		(*str)++;
		if (**str == '-')
			elements->flags = '-';
	}
	while (**str == '0' || **str == '-')
		(*str)++;
}

void	check_width(const char **str, t_printf *elements, va_list argsptr)
{
	if (**str == '*')
	{
		elements->width = va_arg(argsptr, int);
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		elements->width = elements->width * 10 + **str - '0';
		(*str)++;
	}
}

void	check_precision(const char **str, t_printf *elements, va_list argsptr)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str > '9')
			elements->indicator_precision = 1;
		while (**str >= '0' && **str <= '9')
		{
			elements->precision = elements->precision * 10 + **str - '0';
			(*str)++;
		}
		if (**str == '*')
		{
			if ((elements->precision = va_arg(argsptr, int)) == 0)
				elements->indicator_precision = 1;
			(*str)++;
		}
		if (elements->precision == 0)
			elements->indicator_precision = 1;
	}
	else
		elements->indicator_precision = -1;
}

void	check_type(const char **str, t_printf *elements)
{
	if (ft_strchr("cspdiuxX%%", **str))
	{
		elements->type = **str;
		(*str)++;
	}
}
