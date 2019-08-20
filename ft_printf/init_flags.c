/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:24:33 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/11 10:56:00 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_fieldwidth(int *i, char *format)
{
    int    num;
    
    num = 0;
    while (format[*i] && ft_isdigit(format[*i]))
    {
        num = num * 10 + (format[*i] - '0');
        (*i)++;
    }
    return (num);
}

static int 	get_precision(int *i, char *format)
{
	int num;

	num = 0;
	(*i)++;
	while (format[*i] && ft_isdigit(format[*i]))
	{	
		num = num * 10 + (format[*i] - '0');
		(*i)++;
	}
	return (num);
}

void	 	init_flags(int *i, int *flags, char *format)
{
	int n;

	n = 0;
	while (n < 6)
	{
		if (n == 4)
			flags[n++] = -1;
		else
			flags[n++] = 0;
	}
	(*i)++;
	while (format[*i] && !(is_conversion(format[*i])))
	{
		if (format[*i] == '-')
			flags[0] = 1;
		else if (format[*i] == '0')
			flags[1] = 1;
		else if (format[*i] == '+')
			flags[2] = 1;
		else if (ft_isdigit(format[*i]))
		{
			flags[3] = get_fieldwidth(i, format);
			(*i)--;
		}
		else if (format[*i] == '.')
		{	
			flags[4] = get_precision(i, format);
			(*i)--;
		}
		else if (format[*i] == '#')
			flags[5] = 1;
		(*i)++;
	}
}
