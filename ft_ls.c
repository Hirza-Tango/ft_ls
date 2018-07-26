/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:40:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 13:22:09 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int					fill_info(const char *name, const char *path,
	t_file_info *info)
{
	errno = 0;
	info->name = ft_strdup(name);
	info->path = (char *)path;
	lstat(info->path, &(info->stat));
	if (errno)
	{
		ft_error(name);
		return (1);
	}
	return (0);
}

void				ft_fileinfodel(void *info, size_t len)
{
	free(((t_file_info *)info)->path);
	free(((t_file_info *)info)->name);
	free(info);
	info = NULL;
	(void)len;
}

static const char	*get_path(const char *location, const char *name)
{
	char			*ret;
	const size_t	size = ft_strlen(location) + ft_strlen(name) + 2;

	ret = ft_strnew(size);
	ret = ft_strcpy(ret, location);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, name, size);
	return (ret);
}

t_list				*get_file_list(const char *location, t_flag flags)
{
	const DIR		*dir_id = opendir(location);
	struct dirent	*ent;
	t_file_info		info;
	t_list			*list;

	if (!dir_id)
	{
		ft_error(location);
		return (NULL);
	}
	list = NULL;
	errno = 0;
	while ((ent = readdir((DIR *)dir_id)))
	{
		if (flags & FLAG_LA || ent->d_name[0] != '.')
			if (!fill_info(ent->d_name, get_path(location, ent->d_name), &info))
				ft_lstappend(&list, ft_lstnew(&info, sizeof(t_file_info)));
		errno = 0;
	}
	if (errno)
		ft_error(location);
	closedir((DIR *)dir_id);
	return (list);
}

void				ft_ls(const char *loc, t_flag flags)
{
	t_list			*list;
	t_file_info		info;
	t_list			*dup;

	list = sort_file_list(get_file_list(loc, flags), flags);
	flags & FLAG_LL ? ls_print_ll(list, flags, 1) : ls_print_normal(list, flags);
	dup = (t_list *)list;
	if (flags & FLAG_UR)
		while (dup)
		{
			info = *((t_file_info *)dup->content);
			if ((info.stat.st_mode & S_IFMT) == S_IFDIR &&
				ft_strcmp(info.name, ".") && ft_strcmp(info.name, ".."))
			{
				ft_printf("\n%s:\n", info.path);
				ft_ls(info.path, flags);
			}
			dup = dup->next;
		}
	ft_lstdel((t_list **)(&list), &ft_fileinfodel);
}
