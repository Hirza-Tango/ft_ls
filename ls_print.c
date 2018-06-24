/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:06:41 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/24 17:54:31 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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

	ft_printf("total %zu\n", /*number of blocks*/);
	while (list)
	{
		f = *(t_file_info *)list->content;
		print_permissions(f.stat.st_mode);
		ft_printf("  %2hu", f.stat.st_nlink);
		if (!(flags & FLAG_LG))
			ft_printf("  %8s", ln_set ? f.passwd.pw_uid : f.passwd.pw_name);
		if (!(flags & FLAG_LO))
			ft_printf("  %8s", ln_set ? f.group.gr_gid : f.group.gr_name);
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