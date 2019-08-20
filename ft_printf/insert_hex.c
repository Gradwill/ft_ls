/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:24:27 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/11 16:23:04 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		process_1(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[1])
	{
		if (flag[5])
			ft_putstr("0x");
		fc = '0';
	}
	while (flag[3]--)
		ft_putchar(fc);
	if (flag[5] && !flag[1])
		ft_putstr("0x");
	ft_puthex(dec);
}

void		insert_hex(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[5])
		flag[3] -= 2;
	if ((flag[3] -= ft_hexcount(dec)) > 0)
	{
		if (!flag[0])
			process_1(dec, flag);
		else
		{
			if (flag[5])
				ft_putstr("0x");
			ft_puthex(dec);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
	{
		if (flag[5])
			ft_putstr("0x");
		ft_puthex(dec);
	}
}
