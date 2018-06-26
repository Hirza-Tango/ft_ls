/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_dirent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:54:54 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/26 17:04:55 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare_lc(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_ctimespec.tv_sec - b->stat.st_ctimespec.tv_sec;

	if (!ret)
		return(compare_default(a, b));
	return ((int)ret);
}

int		compare_lu(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_atimespec.tv_sec - b->stat.st_atimespec.tv_sec;

	if (!ret)
		return(compare_default(a, b));
	return ((int)ret);
}

int		compare_uu(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_birthtimespec.tv_sec - b->stat.st_birthtimespec.tv_sec;

	if (!ret)
		return(compare_default(a, b));
	return ((int)ret);
}

int		compare_lt(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_mtimespec.tv_sec - b->stat.st_mtimespec.tv_sec;

	if (!ret)
		return(compare_default(a, b));
	return ((int)ret);
}

int		compare_us(const t_file_info *a, const t_file_info *b)
{
	const long	ret = a->stat.st_size - b->stat.st_size;

	if (!ret)
		return(compare_default(a, b));
	return ((int)ret);
}
