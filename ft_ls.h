/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:57:14 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 11:36:12 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

int             dir_count(const char *filename);
void            sort_ascending(struct dirent **dir);
void            sort_descending(struct dirent **dir);
void			sort_ltime(struct dirent **dir, char const *pdir);
void			sort_etime(struct dirent **dir, char const *pdir);
struct dirent	**init_dirent(const char *filename);
struct dirent	**init_files(struct dirent **d, int argc, char **argv, int count);
int				parse_flag(char **args, int argc, int *f);
void			format_l(struct dirent **dir, int *flag, const char *pdir);
void			format_R(struct dirent **dir, char const *pdir, int *flag);
int				ft_timecmp(struct timespec ts1, struct timespec ts2);
void			print_flag(struct dirent **dir, int *flag, char const *pdir);
#endif
