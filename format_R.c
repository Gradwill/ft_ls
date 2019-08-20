/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_R.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:21:32 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/23 18:14:24 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		format_R(struct dirent **dir, char const *pdir, int *flag)
{
	struct stat 	sfile;
	struct dirent 	**d;
	char			*fpath;
	
	while (*dir)
	{
		stat((fpath = ft_strjoin_d(pdir, (*dir)->d_name, '/')), &sfile);
		if ((sfile.st_mode & S_IFDIR) && ((*dir)->d_name)[0] != '.')
		{
			ft_printf("\n%s:\n", fpath);
			print_flag((d = init_dirent(fpath)), flag, fpath);
		}
		dir++;
	}
}
