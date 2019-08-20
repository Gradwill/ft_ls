/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:52:03 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/10 12:57:18 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(char *format, ...);
void		init_flags(int *i, int *flags, char *format);
char		is_conversion(char c);
void		insert_string(char *sarg, int *flag);
void		insert_decimal(int dec, int *flag);
void		insert_char(char c, int *flag);
void		insert_percent(int *flag);
void		insert_wstring(wchar_t *wc, int *flag);
void		insert_wchar(wchar_t wc, int *flag);
void		insert_octal(int dec, int *flag);
void		insert_hex(int dec, int *flag);
void		insert_udecimal(unsigned int dec, int *flag);
void		insert_hex_u(int dec, int *flag);
#endif
