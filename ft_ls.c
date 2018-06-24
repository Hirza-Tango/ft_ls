/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:40:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/24 17:38:04 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>


t_list	**get_file_list(const char *location, t_flag flags)
{
	const DIR		*dir_id = opendir(location);
	struct dirent	*entry;
	t_file_info		*info;
	t_list			**list;
	
	if (!dir_id)
		//TODO:handle
		return (NULL);
	
	while ((entry = readdir((DIR *)dir_id)))
	{
		info->dirent = *entry;
		info->path = ft_strjoin(location, entry->d_name);
		//check for trailing slash
		lstat(info->path, &info->stat);
		//TODO: handle bad stat
		if (flags & FLAG_LL)
		{	
			info->passwd = *getpwuid((info->stat.st_uid));
			info->group = *getgrgid((info->stat.st_gid));
			//listxattr(info->path);
		}
		if (flags & FLAG_LA || entry->d_name[0] != '.')
			ft_lstadd(list, ft_lstnew(info, sizeof(info)));
	}
	closedir((DIR *)dir_id);
	return (list);
}

void	ft_ls(const char *location, t_flag flags)
{
	t_list	**list = get_file_list(location, flags);

	sort_file_list(list, flags, location);
	if (flags & FLAG_LL)
		ls_print_ll(*list, flags);
	else
		ls_print_normal(*list, flags);


	//if (flags & FLAG_R)
		//for files which are directories
			//ft_printf("%s:\n", filename)
			//ft_ls(filename, flags)
			//if (!last_entry_in_list)
				//ft_printf("\n");
}