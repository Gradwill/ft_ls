/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:49:19 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/09 11:02:13 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sub_f1(wchar_t *wc, int *flag)
{
	char fc;

	fc = ' ';
	if (!flag[0])
	{
		if (flag[1])
			fc = '0';
		while (flag[3]--)
			ft_putchar(fc);
		ft_putwstr(wc);
	}
	else
	{
		ft_putwstr(wc);
		while (flag[3]--)
			ft_putchar(fc);
	}
}

void		insert_wstring(wchar_t *wc, int *flag)
{
	if ((flag[4] >= 0) && ft_wstrlen(wc) > (size_t)flag[4])
		wc = ft_wstrsub(wc, 0, flag[4]);
	if ((flag[3] -= ft_wstrlen(wc)) > 0)
		sub_f1(wc, flag);
	else
		ft_putwstr(wc);
}
