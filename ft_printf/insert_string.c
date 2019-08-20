/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:08:20 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/09 11:02:07 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sub_f1(char *s, int *flag)
{
	char fc;

	fc = ' ';
	if (!flag[0])
	{
		if (flag[1])
			fc = '0';
		while (flag[3]--)
			ft_putchar(fc);
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		while (flag[3]--)
			ft_putchar(fc);
	}
}

void		insert_string(char *sarg, int *flag)
{
	if ((flag[4] >= 0) && ft_strlen(sarg) > (size_t)flag[4])
		sarg = ft_strsub(sarg, 0, flag[4]); 
	if ((flag[3] -= ft_strlen(sarg)) > 0)
		sub_f1(sarg, flag);
	else
		ft_putstr(sarg);
}
