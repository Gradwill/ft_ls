/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:50:31 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/08 09:22:34 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		insert_percent(int *flag)
{
	char fc;

	fc = ' ';
	if ((flag[3] -= 1) > 0)
	{
		if (!flag[0])
		{
			if (flag[1])
				fc = '0';
			while (flag[3]--)
				ft_putchar(fc);
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
		ft_putchar('%');
}
