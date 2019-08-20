/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:24:27 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/11 16:06:33 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		process_1(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[1])
		fc = '0';
	while (flag[3]--)
		ft_putchar(fc);
	if (flag[5])
		ft_putchar('0');
	ft_putoctal(dec);
}

void		insert_octal(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[5])
		flag[3] -= 1;
	if ((flag[3] -= ft_octcount(dec)) > 0)
	{
		if (!flag[0])
			process_1(dec, flag);
		else
		{
			if (flag[5])
				ft_putchar('0');
			ft_putoctal(dec);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
	{
		if (flag[5])
			ft_putchar('0');
		ft_putoctal(dec);
	}
}
