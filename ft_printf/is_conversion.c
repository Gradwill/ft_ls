/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:53:32 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/10 13:18:45 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char            is_conversion(char c)
{
    if (c == 's' || c == 'd' || c == 'c' || c == '%')
        return (c);
	else if (c == 'l' || c == 'S' || c == 'C' || c == 'o')
		return (c);
	else if (c == 'D' || c == 'O' || c == 'x' || c == 'X')
		return (c);
	else if (c == 'u' || c == 'U' || c == 'i')
		return (c);
    else
        return (0);
}
