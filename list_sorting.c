/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:55:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/24 14:59:52 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare_default(const t_file_info a, const t_file_info b)
{
	return (ft_strcmp(a.dirent.d_name, b.dirent.d_name));
}

static void	sort_list_by(t_list **list,
	int (*compare)(const t_file_info, const t_file_info), char reverse)
{
//TODO: write sorter
}

void	sort_file_list(t_list **list, t_flag flags, const char *location)
{
	const char reverse = flags & FLAG_LR;
	
	if (flags & FLAG_LF)
		return ;
	sort_list_by(list, compare_default, reverse);
	if (flags & FLAG_LT)
	{
		if (flags & FLAG_LC)
			sort_list_by(list, compare_lc, reverse);
		else if (flags & FLAG_LU)
			sort_list_by(list, compare_lu, reverse);
		else if (flags & FLAG_UU)
			sort_list_by(list, compare_uu, reverse);
		else
			sort_list_by(list, compare_ut, reverse);
	}
	else if (flags & FLAG_US)
		sort_list_by(list, compare_us, reverse);
}