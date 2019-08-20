/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:18:55 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/17 11:20:13 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int        dir_count(const char *filename)
{
    DIR				*d;
    struct dirent	*dir;
    int				count;
    
    if ((d = opendir(filename)))
    {
        count = 0;
        while ((dir = readdir(d)))
            count++;
        (void)closedir(d);
        return (count);
    }
    return (-1);
}
