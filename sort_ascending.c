/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:20:20 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 11:24:13 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    sort_ascending(struct dirent **dir)
{
    int                smaller;
    struct dirent    *temp;
    size_t             i;
    size_t             ii;
    
    i = 0;
    while (dir[i])
    {
        ii = i + 1;
        smaller = i;
        while (dir[ii])
        {
            if (ft_strcmp((dir[smaller])->d_name, (dir[ii])->d_name) > 0)
                smaller = ii;
            ii++;
        }
        temp = dir[i];
        dir[i] = dir[smaller];
        dir[smaller] = temp;
        i++;
    }
}
