/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:49:19 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/08 17:00:09 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		insert_char(char c, int *flag)
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
			ft_putchar(c);
		}
		else
		{
			ft_putchar(c);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
		ft_putchar(c);
}
