/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:24:27 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/09 13:13:39 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		process_1(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[2] && dec > 0)
	{
		flag[3]--;
	}
	if (flag[1])
	{
		fc = '0';
		if (dec < 0)
		{
			ft_putchar('-');
			dec *= -1;
		}
		else if (flag[2])
			ft_putchar('+');
		flag[2] = 0;
	}
	while (flag[3]--)
		ft_putchar(fc);
	if (flag[2] && dec > 0)
		ft_putchar('+');
	ft_putnbr(dec);
}

void		insert_decimal(int dec, int *flag)
{
	char fc;

	fc = ' ';
	if ((flag[3] -= ft_digscount(dec)) > 0)
	{
		if (!flag[0])
			process_1(dec, flag);
		else
		{
			if (flag[2] && dec > 0)
			{
				ft_putchar('+');
				flag[3]--;
			}
			ft_putnbr(dec);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
	{
		if (flag[2] && dec > 0)
			ft_putchar('+');
		ft_putnbr(dec);
	}
}
