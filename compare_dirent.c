/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_dirent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:54:54 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/24 11:27:52 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long		compare_lc(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_ctimespec.tv_sec - b->stat.st_ctimespec.tv_sec;

	if (!ret)
		return (compare_default(a, b));
	return (ret);
}

long		compare_lu(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_atimespec.tv_sec - b->stat.st_atimespec.tv_sec;

	if (!ret)
		return (compare_default(a, b));
	return (ret);
}

long		compare_uu(const t_file_info *a, const t_file_info *b)
{
	long	ret;

	ret = a->stat.st_birthtimespec.tv_sec - b->stat.st_birthtimespec.tv_sec;
	if (!ret)
		return (compare_default(a, b));
	return (ret);
}

long		compare_lt(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_mtimespec.tv_sec - b->stat.st_mtimespec.tv_sec;

	if (!ret)
		return (compare_default(a, b));
	return (ret);
}

long		compare_us(const t_file_info *a, const t_file_info *b)
{
	const long	ret = b->stat.st_size - a->stat.st_size;

	if (!ret)
		return (compare_default(a, b));
	return (ret);
}
