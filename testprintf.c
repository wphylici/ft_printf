/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:08:08 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/14 04:09:21 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	//int len;
	//int a;

	//a = 12345678;
	//char a = 'p';
	//char s_hidden[] = "7";
	//ft_printf("this %i number", 17);
	//printf("hello, %s.", "gavin");

	//printf("\n***|---------------------------|***\n\n");

	ft_printf("me:%*.4d|\n", -5, -9477);
	printf("pf:%*.4d|\n\n", -5, -9477);
	ft_printf("me:%*.2d|\n", 4, -9477);
	printf("pf:%*.2d|\n\n", 4, -9477);
	ft_printf("me:%*.4d|\n", -4, 9477);
	printf("pf:%*.4d|\n\n", -4, 9477);
	ft_printf("me:%*.4d|\n", 4, 9477);
	printf("pf:%*.4d|\n\n", 4, 9477);
	ft_printf("me:%*.3d|\n", 8, -9477);
	printf("pf:%*.3d|\n\n", 8, -9477);
	ft_printf("me:%*.4d|\n", -8, -9477);
	printf("pf:%*.4d|\n\n", -8, -9477);
	ft_printf("me:%*.5d|\n", 8, -9477);
	printf("pf:%*.5d|\n\n", 8, -9477);
	ft_printf("me:%*.4d|\n", 8, 9477);
	printf("pf:%*.4d|\n\n", 8, 9477);
	ft_printf("me:%*.4d|\n", -8, 9477);
	printf("pf:%*.4d|\n\n", -8, 9477);
	ft_printf("me:%*.2d|\n", 8, 9477);
	printf("pf:%*.2d|\n\n", 8, 9477);

	printf("\n***|---------------------------|***\n\n");

	ft_printf("me:%*.*d|\n", 4, 10, 1332);
	printf("pf:%*.*d|\n\n", 4, 10, 1332);
	ft_printf("me:%*.*d|\n", -6, 10, -31332);
	printf("pf:%*.*d|\n\n", -6, 10, -31332);
	ft_printf("me:%*.*d|\n", -5, 10, 31332);
	printf("pf:%*.*d|\n\n", -5, 10, 31332);
	ft_printf("me:%*.*d|\n", -5, 10, -31332);
	printf("pf:%*.*d|\n\n", -5, 10, -31332);
	ft_printf("me:%*.*d|\n", -4, -10, -31332);
	printf("pf:%*.*d|\n\n", -4, -10, -31332);
	ft_printf("me:%*.*d|\n", -6, 7, -31332);
	printf("pf:%*.*d|\n\n", -6, 7, -31332);
	ft_printf("me:%*.*d|\n", -6, -7, -31332);
	printf("pf:%*.*d|\n\n", -6, -7, -31332);
	ft_printf("me:%*.*d|\n", 5, 10, 31332);
	printf("pf:%*.*d|\n\n", 5, 10, 31332);

	printf("\n***|---------------------------|***\n\n");

	ft_printf("me:%*.*d|\n", 8, 5, 1122);
	printf("pf:%*.*d|\n\n", 8, 5, 1122);         ///
	ft_printf("me:%*.*d|\n", 6, 8, -1122222);
	printf("pf:%*.*d|\n\n", 6, 8, -1122222);		///
	ft_printf("me:%*.*d|\n", 7, 7, -1122);
	printf("pf:%*.*d|\n\n", 7, 7, -1122);
	ft_printf("me:%*.*d|\n", 10, 15, -1122);
	printf("pf:%*.*d|\n\n", 10,  15, -1122);
	ft_printf("me:%*.*d|\n", 7, 9, -1122666);
	printf("pf:%*.*d|\n\n", 7, 9, -1122666);
	ft_printf("me:%*.*d|\n", 15, 9, -1122666);
	printf("pf:%*.*d|\n\n", 15, 9, -1122666);
	ft_printf("me:%8.5d|\n", 34);
	printf("pf:%8.5d|\n\n", 34);


	ft_printf("me:%*.*d|\n", -20, 11, 1111226);
	printf("pf:%*.*d|\n\n", -20, 11, 1111226);


	ft_printf("me:%*.*d|\n", 15, 8, 111122);
	printf("pf:%*.*d|\n\n", 15, 8, 111122);

	ft_printf("me:%X\n", 255);
	//ft_printf("%-8.5d|\n", 34);
	//printf("%-8.5d|\n", 34);
	//ft_printf("%-10.2d\n", 33333);
	//printf("%-10.2d\n", 33333);
	//ft_printf("%-3.7d\n", -33333);
	//printf("%-3.7d\n", -33333);
	//ft_printf("%-10.5d\n", 33);
	//printf("%-10.5d\n", 33);
	//ft_printf("%-8.3d\n", -8473);
	//printf("%-8.3d\n", -8473);
	//ft_printf("%-3.3d\n", 6983);
	//printf("%-3.3d\n", 6983);
	//ft_printf("%-*.*d\n", -10, 5, 6983);
	//printf("%-*.*d\n", -10, 5, 6983);
	//ft_printf("%-*.*d\n", -10, 2, 33333);
	//printf("%-*.*d\n", -10, 2, 33333);
	//ft_printf("%-*.*d\n", -10, 6, -33333); //
	//printf("%-*.*d\n", -10, 6, -33333);
	//ft_printf("%-*.*d\n", 10, -7, -33333); //
	//printf("%-*.*d\n", 10, -7, -33333);
	//ft_printf("%-*.*d\n", -7, 10, -3333);
	//printf("%-*.*d\n", -7, 10, -3333);  //
	//ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	//printf("%% *.5i 42 == |%     *.5i|", 4, 42);

	//printf("this %x number", 17);
	//int a;
	//int b;s
	//char c;

	//b = 0;
	//a = 5636 % 16;


	//printf("%d", a);
	//printf("%d\n", len);
	//len = printf("Hello\n");
	//printf("%d\n", len);

	//printf("%d", a);
	return (0);
}
