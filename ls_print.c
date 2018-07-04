/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:06:41 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/04 13:56:26 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		print_id(t_file_info f, t_flag flags)
{
	const char	ln_set = flags & FLAG_LN;

	if (!(flags & FLAG_LG))
	{
		if (ln_set || !f.passwd.pw_name)
			ft_printf("  %10u", f.stat.st_uid);
		else
			ft_printf("  %10s", f.passwd.pw_name);
	}
	if (!(flags & FLAG_LO))
	{
		if (ln_set || !f.group.gr_name)
			ft_printf("  %10u", f.stat.st_gid);
		else
			ft_printf("  %10s", f.group.gr_name);
	}
}

static char		get_type_print(mode_t mode)
{
	const mode_t type = mode & S_IFMT;

	if (type == S_IFDIR)
		return ('/');
	if (type == S_IFLNK)
		return ('@');
	if (type == S_IFSOCK)
		return ('=');
	if (type == S_IFWHT)
		return ('%');
	if (type == S_IFIFO)
		return ('|');
	if (mode & S_IXUSR)
		return ('*');
	return (0);
}

void			ls_print_normal(const t_list *list, t_flag flags)
{
	t_list	*dup;

	dup = (t_list *)list;
	while (dup)
	{
		ft_printf("%s\n", ((t_file_info *)dup->content)->name);
		if (flags & FLAG_UF)
			ft_putchar(
				get_type_print(((t_file_info *)dup->content)->stat.st_mode));
		else if (flags & FLAG_LP &&
			(((t_file_info *)dup->content)->stat.st_mode & S_IFMT) == S_IFDIR)
			ft_putchar('/');
		dup = dup->next;
	}
}

void			ls_print_ll_one(t_file_info f, t_flag flags)
{
	char		*buff;

	print_permissions(f.stat.st_mode);
	ft_printf("  %2hu", f.stat.st_nlink);
	print_id(f, flags);
	ft_printf("  %8lld", f.stat.st_size);
	print_time(f.stat, flags);
	ft_printf(" %s", f.name);
	if ((f.stat.st_mode & S_IFMT) == S_IFLNK)
	{
		buff = (char *)malloc(f.stat.st_size + 1);
		if (readlink(f.path, buff, f.stat.st_size) < 0)
			error(f.name);
		buff[f.stat.st_size] = 0;
		ft_printf(" -> %s", buff);
		free(buff);
	}
	if (flags & FLAG_UF)
		ft_putchar(get_type_print(f.stat.st_mode));
	else if (flags & FLAG_LP &&	(f.stat.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void			ls_print_ll(const t_list *list, t_flag flags)
{
	t_list	*dup;
	size_t	blocks;

	if (!(dup = (t_list *)list))
		return ;
	blocks = 0;
	while (dup)
	{
		blocks += ((t_file_info *)dup->content)->stat.st_blocks;
		dup = dup->next;
	}
	ft_printf("total %zu\n", blocks);
	while (list)
	{
		ls_print_ll_one(*(t_file_info *)list->content, flags);
		list = list->next;
	}
}
