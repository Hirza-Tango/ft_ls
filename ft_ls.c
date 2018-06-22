/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:40:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/22 18:52:27 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	sort_list_by(t_list **list,
	int (*compare)(const struct dirent, const struct dirent), char reverse,
	const char *location);

static void	sort_file_list(t_list **list, t_flag flags, const char *location)
{
	const char reverse = flags & FLAG_LR;
	
	if (flags & FLAG_LF)
		return ;
	sort_list_by(list, compare_default, reverse, location);
	if (flags & FLAG_LT)
	{
		if (flags & FLAG_LC)
			sort_list_by(list, compare_lc, reverse, location);
		else if (flags & FLAG_LU)
			sort_list_by(list, compare_lu, reverse, location);
		else if (flags & FLAG_UU)
			sort_list_by(list, compare_uu, reverse, location);
		else
			sort_list_by(list, compare_ut, reverse, location);
	}
	else if (flags & FLAG_US)
		pass; //sort_list_by(list, compare_us, reverse, location);
}

t_list	**get_file_list(const char *location, t_flag flags)
{
	const DIR		*dir_id = opendir(location);
	struct dirent	*entry;
	struct stat		stats;
	t_file_info		*info;
	t_list			**list;
	char			*path;
	
	if (!dir_id)
		//TODO:handle
		return (NULL);
	
	while ((entry = readdir((DIR *)dir_id)))
	{
		info->dirent = *entry;
		info->path = ft_strjoin(location, entry->d_name);
		stat(info->path, &info->stat);
		//TODO: handle bad stat
		info->passwd = *getpwuid((info->stat->st_uid));
		info->group = 
		
		
		ft_lstadd(list, ft_lstnew(entry, sizeof(entry)));
	}
	closedir((DIR *)dir_id);
	return (list);
}

void	ft_ls(const char *location, t_flag flags)
{
	t_list	**list = get_file_list(location, flags);

	sort_file_list(list, flags, location);
	//print based on style


	//if (flags & FLAG_R)
		//for files which are directories
			//ft_printf("%s:\n", filename)
			//ft_ls(filename, flags)
			//if (!last_entry_in_list)
				//ft_printf("\n");
}