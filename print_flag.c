/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:09:48 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 11:34:09 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_flag(struct dirent **dir, int *flag, char const *pdir)
{
    int i;
	
	i = 0;
	sort_ascending(dir);
    if (flag[4] && flag[3])
        sort_etime(dir, pdir);
    else if (flag[4])
        sort_ltime(dir, pdir);
    else if (flag[3])
        sort_descending(dir);
    if (flag[0])
        format_l(dir, flag, pdir);
    else if (flag[2])
        while (dir[i])
            ft_printf("%s\n", (dir[i++])->d_name);
    else
        while (dir[i])
        {
            if ((dir[i]->d_name)[0] != '.')
                ft_printf("%s\n", dir[i]->d_name);
            i++;
        }
	if (pdir && flag[1])
		format_R(dir, pdir, flag);
}
