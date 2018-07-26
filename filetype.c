/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:35:48 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 16:36:58 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	ft_isdir(const char *dir)
{
	struct stat	s;

	if (lstat(dir, &s))
		return (-1);
	if ((s.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

int	ft_islnk(const char *dir)
{
	struct stat	s;

	if (lstat(dir, &s))
		return (-1);
	if ((s.st_mode & S_IFMT) == S_IFLNK)
		return (1);
	return (0);
}
