/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:38:37 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/24 15:59:01 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

static char	get_type(mode_t mode)
{
	if (mode & S_IFIFO)
		return ('p');
	else if (mode & S_IFCHR)
		return ('c');
	else if (mode & S_IFDIR)
		return ('d');
	else if (mode & S_IFBLK)
		return ('b');
	else if (mode & S_IFREG)
		return ('-');
	else if (mode & S_IFLNK)
		return ('l');
	else if (mode & S_IFSOCK)
		return ('s');
	else if (mode & S_IFWHT)
		return ('w');
	exit (-1);
}

void		print_permissions(mode_t mode)
{
	ft_putchar(get_type(mode));
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