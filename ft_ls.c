/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:27:09 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 13:50:44 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	struct dirent 	**dir;
	struct dirent   **tdir;
	int				count;
	int				flag[5]; /* f[0] = -l, f[1] = -R, f[2] = -a, f[3] = -r, f[4] = -t */
	
	dir = init_dirent(".");
	if ((count = parse_flag(argv, argc, flag)))
	{
		tdir = init_files(dir, argc, argv, count);
		free(dir);
		dir = tdir;
	}
	print_flag(dir, flag, ".");
	free(dir);
	return (0);
}
	
