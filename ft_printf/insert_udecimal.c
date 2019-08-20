/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:24:27 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/10 11:11:41 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_1(unsigned int dec, int *flag)
{
	char fc;

	fc = ' ';
	if (flag[2])
	{
		flag[3]--;
	}
	if (flag[1])
	{
		fc = '0';
		if (flag[2])
			ft_putchar('+');
		flag[2] = 0;
	}
	while (flag[3]--)
		ft_putchar(fc);
	if (flag[2])
		ft_putchar('+');
	ft_putunbr(dec);
}

void		insert_udecimal(unsigned int dec, int *flag)
{
	char fc;

	fc = ' ';
	if ((flag[3] -= ft_udigscount(dec)) > 0)
	{
		if (!flag[0])
			process_1(dec, flag);
		else
		{
			if (flag[2])
			{
				ft_putchar('+');
				flag[3]--;
			}
			ft_putunbr(dec);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
	{
		if (flag[2])
			ft_putchar('+');
		ft_putunbr(dec);
	}
}
