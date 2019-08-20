/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:49:19 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/09 12:07:01 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		insert_wchar(wchar_t wc, int *flag)
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
			ft_putwchar(wc);
		}
		else
		{
			ft_putwchar(wc);
			while (flag[3]--)
				ft_putchar(fc);
		}
	}
	else
		ft_putwchar(wc);
}
