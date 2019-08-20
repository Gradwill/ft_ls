/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:21:36 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/17 09:48:45 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		next_conversion(char *form, int *i)
{
	int ii;

	while (form[*i] && form[*i] != '%')
		ft_putchar(form[(*i)++]);
	if (form[*i] == '%')
	{
		ii = *i + 1;
		while (!is_conversion(form[ii]))
		{
			if (ft_isalpha(form[ii]))
		    {
				ft_putchar('%');
				return (form[++*i]);
			}
			ii++;
		}
	}	
	return (form[*i]);
}

static void		process_ell(char *conv, va_list vlist, int *flag)
{
	if (*conv == 's')
		insert_wstring(va_arg(vlist, wchar_t *), flag);
}	

static void		process_conversion(char *conv, va_list vlist, int *flag)
{
	if (*conv == 'l')
		process_ell((conv + 1), vlist, flag);
	else if (*conv == 'S')
		insert_wstring(va_arg(vlist, wchar_t *), flag);
	else if (*conv == 's')
		insert_string(va_arg(vlist, char *), flag);
	else if (*conv == 'u' || *conv == 'U')
		insert_udecimal(va_arg(vlist, unsigned int), flag);
	else if (*conv == 'd' || *conv == 'D' || *conv == 'i')
		insert_decimal(va_arg(vlist, int), flag);
	else if (*conv == 'o' || *conv == 'O')
		insert_octal(va_arg(vlist, int), flag);
	else if (*conv == 'x')
		insert_hex(va_arg(vlist, int), flag);
	else if (*conv == 'X')
		insert_hex_u(va_arg(vlist, int), flag);
	else if (*conv == 'c')
		insert_char(va_arg(vlist, int), flag);
	else if (*conv == 'C')
		insert_wchar(va_arg(vlist, wchar_t), flag);
	else if (*conv == '%')
		insert_percent(flag);
}
		
int		ft_printf(char *format, ...)
{
	int 	i;
	int		flag[6]; /* f[0] == dash, f[1] == zero, f[2] == plus, f[3] == fieldwidth, f[4] == precision 
				ear
			git 	f[5] = hashtag */
	va_list vlist;

	i = 0;
	va_start(vlist, format);
	while (format[i])
	{
		if ((next_conversion(format, &i)) == '\0')
			break ;	
		if (format[i] == '%')
			init_flags(&i, flag, format);	
		if (is_conversion(format[i]))
		{
			process_conversion((format + i), vlist, flag);
			if (format[i] == 'l')
				i++;
			i++;
		}
	}
	va_end(vlist);
	return (1);
}
