/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_descending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:20:31 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/16 17:20:35 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    sort_descending(struct dirent **dir)
{
    int                bigger;
    struct dirent    *temp;
    size_t             i;
    size_t             ii;
    
    i = 0;
    while (dir[i])
    {
        ii = i + 1;
        bigger = i;
        while (dir[ii])
        {
            if (ft_strcmp((dir[bigger])->d_name, (dir[ii])->d_name) < 0)
                bigger = ii;
            ii++;
        }
        temp = dir[i];
        dir[i] = dir[bigger];
        dir[bigger] = temp;
        i++;
    }
}
