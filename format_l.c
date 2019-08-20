/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:11:22 by gngobeni          #+#    #+#             */
/*   Updated: 2019/07/24 16:51:43 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	process_f(struct stat *sfile)
{
	ft_printf("%c%c%c%c", (sfile->st_mode & S_IFDIR) ? 'd' : \
		(sfile->st_mode & S_IFREG) ? '-' : \
		(sfile->st_mode & S_IFLNK) ? 'l': \
		(sfile->st_mode & S_IFSOCK) ? 's': \
		(sfile->st_mode & S_IFBLK) ? 'b' : \
		(sfile->st_mode & S_IFCHR) ? 'c' : \
		(sfile->st_mode & S_IFIFO) ? 'p' : '?', \
		(sfile->st_mode & S_IRUSR) ? 'r' : '-', \
		(sfile->st_mode & S_IWUSR) ? 'w' : '-', \
		(sfile->st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c%c%c", (sfile->st_mode & S_IRGRP) ? 'r' : '-', \
		(sfile->st_mode & S_IWGRP) ? 'w' : '-', \
		(sfile->st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c%c%c", (sfile->st_mode & S_IROTH) ? 'r' : '-', \
		(sfile->st_mode & S_IWOTH) ? 'w' : '-', \
		(sfile->st_mode & S_IXOTH) ? 'x' : '-');
}

void		sort_dir(struct dirent **dir, int *flag, char const *pdir)
{
	if (flag[4] && flag[3]) 
		sort_etime(dir, pdir);
	else if (flag[3])
		sort_descending(dir);
	else if (flag[4])
		sort_ltime(dir, pdir);
	else
		sort_ascending(dir);
}

void		format_l(struct dirent **dir, int *flag, const char *pdir)
{
	struct stat		sfile;
	struct group	*grp;
	struct passwd	*pwd;
	char		*buf;

	sort_dir(dir, flag, pdir);
	while (*dir)
	{
		if (!flag[2] && ((*dir)->d_name)[0] == '.')
		{
			dir++;
			continue ;
		}
		stat(ft_strjoin_d(pdir, (*dir)->d_name, '/'), &sfile);
		grp = getgrgid(sfile.st_gid);
		pwd = getpwuid(sfile.st_uid);
		process_f(&sfile);
		ft_printf("%4d", (sfile.st_mode & S_IFDIR) ? \
			dir_count((*dir)->d_name) : 1);
		ft_printf(" %s", pwd ? pwd->pw_name : "?");
		ft_printf("  %s", grp ? grp->gr_name : "?");
		buf = ft_strsub(ctime(&sfile.st_mtime), 4, 12);
		ft_printf("%6d %s", sfile.st_size, buf);
		ft_printf(" %s\n", (*dir)->d_name);
		dir++;
	}
}
