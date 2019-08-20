/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dirent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:20:02 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/23 18:00:47 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
			
struct dirent        **init_dirent(const char *filename)
{
    int             count;
    int                i;
    struct dirent    **dir;
	DIR				*d;
    

    if ((d = opendir(filename)) && (count = dir_count(filename)) > 0)
    {
        i = 0;
        if ((dir = (struct dirent **)malloc(sizeof(struct dirent *) * (count + 1))))
        {
            while (i < count)
            {
                dir[i] = readdir(d);
                i++;
            }
            dir[i] = NULL;
            return (dir);
        }
        else
            return (NULL);
    }
    else
        return (NULL);
}
