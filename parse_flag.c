/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:34:36 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/22 18:13:29 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	init_f(int *f, int len)
{
	int i;

	i = 0;
	while (i < len)
		f[i++] = 0;
}

static void	multiparse(char *arg, int *f)
{
	while (*arg)
	{
		if (*arg == 'l')
			f[0] = 1;
		else if (*arg == 'R')
			f[1] = 1;
		else if (*arg == 'a')
			f[2] = 1;
		else if (*arg == 'r')
			f[3] = 1;
		else if (*arg == 't')
			f[4] = 1;
		arg++;
	}
}

int		parse_flag(char **args, int argc, int *f)
{
	int	i;
	int	fc;

	init_f(f, 5);
	i = 1;
	fc = 0;
	while (i < argc)
	{
		if (args[i][0] != '-')
			fc++;
		else if (ft_strequ(args[i], "-l"))
			f[0] = 1;
		else if (ft_strequ(args[i], "-R"))
			f[1] = 1;
		else if (ft_strequ(args[i], "-a"))
			f[2] = 1;
		else if (ft_strequ(args[i], "-r"))
			f[3] = 1;
		else if (ft_strequ(args[i], "-t"))
			f[4] = 1;
		else
			multiparse(args[i], f);
		i++;
	}
	return (fc);
}

