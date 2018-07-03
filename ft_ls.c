/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:40:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/03 15:51:35 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_fileinfodel(void *info, size_t len)
{
	free(((t_file_info *)info)->path);
	free(info);
	info = NULL;
	(void)len;
}

static char	*get_path(const char *location, const char *name)
{
	char			*ret;
	const size_t	size = ft_strlen(location) + ft_strlen(name) + 2;

	ret = ft_strnew(size);
	ret = ft_strcpy(ret, location);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, name, size);
	return (ret);
}

t_list		*get_file_list(const char *location, t_flag flags)
{
	const DIR		*dir_id = opendir(location);
	struct dirent	*entry;
	t_file_info		info;
	t_list			*list;

	if (!dir_id)
		exit(2);
	list = NULL;
	//handle
	while ((entry = readdir((DIR *)dir_id)))
	{
		if (flags & FLAG_LA || entry->d_name[0] != '.')
		{
			info.dirent = *entry;
			info.path = get_path(location, entry->d_name);
			lstat(info.path, &(info.stat));
			//handle
			info.passwd = *getpwuid((info.stat.st_uid));
			info.group = *getgrgid((info.stat.st_gid));
			ft_lstappend(&list, ft_lstnew(&info, sizeof(t_file_info)));
		}
	}
	closedir((DIR *)dir_id);
	return (list);
}

void		ft_ls(const char *location, t_flag flags)
{
	t_list		*list;
	t_file_info	info;
	t_list		*dup;

	list = get_file_list(location, flags);
	sort_file_list(&list, flags);
	if (flags & FLAG_LL)
		ls_print_ll(list, flags);
	else
		ls_print_normal(list, flags);
	dup = list;
	if (flags & FLAG_UR)
		while (dup)
		{
			info = *((t_file_info *)dup->content);
			if ((info.stat.st_mode & S_IFMT) == S_IFDIR &&
				ft_strcmp(info.dirent.d_name, ".") &&
				ft_strcmp(info.dirent.d_name, ".."))
			{
				ft_printf("\n%s:\n", info.path);
				ft_ls(info.path, flags);
			}
			dup = dup->next;
		}
	ft_lstdel(&list, &ft_fileinfodel);
}
