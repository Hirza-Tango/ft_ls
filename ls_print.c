/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:06:41 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/27 13:36:02 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

size_t	count_blocks(t_list *list)
{
	t_list	*dup;
	size_t	ret;

	dup = list;
	ret = 0;
	while (dup)
	{
		ret += ((t_file_info *)dup->content)->stat.st_blocks;
		dup = dup->next;
	}
	return (ret);
}

void	ls_print_normal(t_list *list, t_flag flags)
{
	while (list)
	{
		ft_printf("%s\n", ((t_file_info *)list->content)->dirent.d_name);
		list = list->next;
	}
}

void	ls_print_ll(t_list *list, t_flag flags)
{
	t_file_info	f;
	const char	ln_set = flags & FLAG_LN;
	char		*buff;

	ft_printf("total %zu\n", count_blocks(list));
	while (list)
	{
		f = *(t_file_info *)list->content;
		print_permissions(f.stat.st_mode);
		ft_printf("  %2hu", f.stat.st_nlink);
		if (!(flags & FLAG_LG))
		{
			if (ln_set || !f.passwd.pw_name)
				ft_printf("  %10u", f.passwd.pw_uid);
			else
				ft_printf("  %10s", f.passwd.pw_name);
		}
		if (!(flags & FLAG_LO))
		{
			if (ln_set || !f.group.gr_name)
				ft_printf("  %10u", f.group.gr_name);
			else
				ft_printf("  %10s", f.group.gr_gid);
		}
		ft_printf("  %8zu", f.stat.st_size);
		if (flags & FLAG_LC)
			print_time(f.stat.st_ctimespec.tv_sec);
		else if (flags & FLAG_LU)
			print_time(f.stat.st_atimespec.tv_sec);
		else if (flags & FLAG_UU)
			print_time(f.stat.st_birthtimespec.tv_sec);
		else
			print_time(f.stat.st_mtimespec.tv_sec);
		ft_printf(" %s", f.dirent.d_name);
		if (f.stat.st_mode & S_IFLNK)
		{
			buff = (char *)malloc(f.stat.st_size + 1);
			readlink(f.path, buff, f.stat.st_size);
			//handle error
			buff[f.stat.st_size] = 0;
			ft_printf(" -> %s", buff);
			free(buff);
		}
		list = list->next;
	}
}