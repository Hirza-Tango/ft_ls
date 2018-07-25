/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:40:17 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/25 15:21:21 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	get_type_permission(mode_t mode)
{
	const mode_t	type = mode & S_IFMT;

	if (type == S_IFIFO)
		return ('p');
	else if (type == S_IFCHR)
		return ('c');
	else if (type == S_IFDIR)
		return ('d');
	else if (type == S_IFBLK)
		return ('b');
	else if (type == S_IFREG)
		return ('-');
	else if (type == S_IFLNK)
		return ('l');
	else if (type == S_IFSOCK)
		return ('s');
	else if (type == S_IFWHT)
		return ('w');
	return ('?');
}

void		print_permissions(mode_t mode)
{
	ft_putchar(get_type_permission(mode));
	mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISUID)
		mode & S_IXUSR ? ft_putchar('s') : ft_putchar('S');
	else
		mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISGID)
		mode & S_IXGRP ? ft_putchar('s') : ft_putchar('S');
	else
		mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISVTX)
		mode & S_IXOTH ? ft_putchar('t') : ft_putchar('T');
	else
		mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}

static void	print_time_str(time_t secs)
{
	const char	*str = ctime(&secs);

	ft_printf("%.2s", str + 8);
	ft_printf(" %.3s", str + 4);
	if (time(NULL) - (time_t)(60 * 60 * 24 * 30.42 * 6) > secs)
		ft_printf("  %.4s", str + 20);
	else
		ft_printf(" %.5s", str + 11);
}

void		print_time(struct stat s, t_flag flags)
{
	if (flags & FLAG_LC)
		print_time_str(s.st_ctimespec.tv_sec);
	else if (flags & FLAG_LU)
		print_time_str(s.st_atimespec.tv_sec);
	else if (flags & FLAG_UU)
		print_time_str(s.st_birthtimespec.tv_sec);
	else
		print_time_str(s.st_mtimespec.tv_sec);
}

char		get_type_print(mode_t mode)
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
