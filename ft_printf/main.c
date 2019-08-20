/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:46:53 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/16 16:55:14 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ft_printf.h"

void	test(char *s, ...)
{	
	va_list a;

	va_start(a, s);
	for (char *s1 = s; ; s1 = va_arg(a, char *))
		ft_putendl(s1);
	va_end(a);
}

#include <dirent.h>








		
int		main(int argc, char **argv)
{ 
	struct dirent **dir;

	dir = init_dirent(".");
	sort_descending(dir);
	while (*dir)
	{
		if (((*dir)->d_name)[0] != '.')
			ft_printf("%s\n", (*dir)->d_name);
		dir++;
	}
	return (0);
}
