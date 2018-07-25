/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:06:41 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/25 15:13:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		print_id(t_file_info f, t_flag flags, t_ls_spacing space)
{
	const char			ln_set = flags & FLAG_LN;
	const struct stat	s = f.stat;

	if (!(flags & FLAG_LG))
	{
		if (ln_set)
			ft_printf("%-*u  ", space.passwd, s.st_uid);
		else
			ft_printf("%-*s  ", space.passwd, getpwuid(s.st_uid)->pw_name);
	}
	if (!(flags & FLAG_LO))
	{
		if (ln_set)
			ft_printf("%-*u  ", space.group, s.st_gid);
		else
			ft_printf("%-*s  ", space.group, getgrgid(s.st_gid)->gr_name);
	}
}

static void		ls_precount(struct stat s, size_t *blocks, t_ls_spacing *space,
	t_flag flags)
{
	*blocks += s.st_blocks;
	space->links = MAX(space->links, ft_declen(s.st_nlink));
	if (!(flags & FLAG_LG))
	{
		if (flags & FLAG_LN)
			space->passwd = MAX(space->passwd, ft_declen(s.st_uid));
		else
			space->passwd = MAX(space->passwd, ft_strlen(
				getpwuid(s.st_uid)->pw_name));
	}
	if (!(flags & FLAG_LO))
	{
		if (flags & FLAG_LN)
			space->group = MAX(space->group, ft_declen(s.st_gid));
		else
			space->group = MAX(space->group, ft_strlen(
				getgrgid(s.st_gid)->gr_name));
	}
	space->size = MAX(space->size, ft_declen(s.st_size));
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

void			ls_print_ll_one(t_file_info f, t_flag flags, t_ls_spacing space)
{
	char		*buff;

	print_permissions(f.stat.st_mode);
	ft_printf("  %*hu ", space.links, f.stat.st_nlink);
	print_id(f, flags, space);
	ft_printf("%*lld ", space.size, f.stat.st_size);
	print_time(f.stat, flags);
	ft_printf(" %s", f.name);
	if ((f.stat.st_mode & S_IFMT) == S_IFLNK)
	{
		buff = (char *)malloc(f.stat.st_size + 1);
		if (readlink(f.path, buff, f.stat.st_size) < 0)
			ft_error(f.name);
		buff[f.stat.st_size] = 0;
		ft_printf(" -> %s", buff);
		free(buff);
	}
	if (flags & FLAG_UF)
		ft_putchar(get_type_print(f.stat.st_mode));
	else if (flags & FLAG_LP && (f.stat.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void			ls_print_ll(const t_list *list, t_flag flags)
{
	t_list			*dup;
	size_t			blocks;
	t_ls_spacing	sp;

	if (!(dup = (t_list *)list))
		return ;
	blocks = 0;
	sp = (t_ls_spacing){0, 0, 0, 0};
	while (dup)
	{
		ls_precount(((t_file_info *)dup->content)->stat, &blocks, &sp, flags);
		dup = dup->next;
	}
	ft_printf("total %zu\n", blocks);
	while (list)
	{
		ls_print_ll_one(*(t_file_info *)list->content, flags, sp);
		list = list->next;
	}
}
