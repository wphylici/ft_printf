/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:17:58 by wphylici          #+#    #+#             */
/*   Updated: 2020/07/27 08:18:39 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_numlen(long long n, t_printf *elements)
{
	int base;

	if (elements->type == 'x' || elements->type == 'X' ||
		elements->type == 'p')
		base = 16;
	else
		base = 10;
	if (n < base && n >= 0)
		return (1);
	else
		return (1 + ft_numlen(n / base, elements));
}

int		ft_putchar_len(char c, int size)
{
	int len;

	len = 0;
	while (size-- > 0)
	{
		write(1, &c, 1);
		len++;
	}
	return (len);
}

int		ft_putnbr_fd(long long n, int fd, t_printf *elements)
{
	if (n < 0)
		n *= (-1);
	if (n >= 16 && (elements->type == 'x' || elements->type == 'X' ||
		elements->type == 'p'))
		ft_putnbr_fd(n / 16, 1, elements);
	else if (n >= 10 && elements->type != 'x' && elements->type != 'X' &&
		elements->type != 'p')
		ft_putnbr_fd(n / 10, 1, elements);
	if (elements->type == 'x' || elements->type == 'p')
		elements->length += ft_putchar_len(n % 16 <= 9 ? n % 16 + '0' :
												n % 16 + 'a' - 10, fd);
	else if (elements->type == 'X')
		elements->length += ft_putchar_len(n % 16 <= 9 ? n % 16 + '0' :
												n % 16 + 'A' - 10, fd);
	else
		elements->length += ft_putchar_len(n % 10 + '0', 1);
	return (0);
}
