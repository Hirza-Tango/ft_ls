/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:38:37 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/04 11:47:45 by dslogrov         ###   ########.fr       */
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
