/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:53:35 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/23 17:30:29 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	struct stat s1, s2;
	struct dirent **d;
	
	d = init_dirent(ft_strjoin_d(".", "ft_printf", '/'));
	if (d)
	while (*d)
		ft_printf("%s\n", (*d++)->d_name);
	//printf("%s\n", ft_strjoin_d(".", "ft_printf", '/'));
	return (0);
}	
