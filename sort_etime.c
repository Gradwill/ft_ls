/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:20:20 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 11:34:25 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    sort_etime(struct dirent **dir, char const *pdir)
{
    int                smaller;
    struct dirent    *temp;
    size_t             i;
    size_t             ii;
    struct stat		sf1;
    struct stat		sf2;
    
    i = 0;
    sort_ascending(dir);
    while (dir[i])
    {
		ii = i + 1;
		smaller = i;
		while (dir[ii])
		{
			stat(ft_strjoin_d(pdir, dir[smaller]->d_name, '/'), &sf1);
			stat(ft_strjoin_d(pdir, dir[ii]->d_name, '/'), &sf2);
			if (ft_timecmp(sf1.st_mtimespec, sf2.st_mtimespec) > 0)
				smaller = ii;
            ii++;
        }
		temp = dir[i];
		dir[i] = dir[smaller];
		dir[smaller] = temp;
		i++;
  	}
}
