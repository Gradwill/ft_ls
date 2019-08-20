
#include "ft_ls.h"

static struct dirent 	*get_dir(struct dirent **ds, char *filename)
{
	while (*ds)
	{
		if (ft_strequ((*ds)->d_name, filename))
			return (*ds);
		ds++;
	}
	return (NULL);
}

struct dirent 		**init_files(struct dirent **d, int argc, char **args, int count)
{
	struct dirent 	**dir;
	int		i;
	int		c;

	i = 1;
	c = 0;
	if ((dir = (struct dirent **)malloc(sizeof(struct dirent *) * (count + 1))))
	{
		while (i < argc)
		{
			if (args[i][0] != '-')
			{
				if (!(dir[c++] = get_dir(d, args[i])))
				{
					ft_printf("ft_ls: cannot access \'%s\': No such file or directory\n", args[i]);
					exit(0);
				}
			}
			i++;
		}
		dir[c] = NULL;
	}
	return (dir);
}
