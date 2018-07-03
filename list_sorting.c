/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:55:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/03 16:33:24 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare_default(const t_file_info *a, const t_file_info *b)
{
	return (-ft_strcmp(a->dirent.d_name, b->dirent.d_name));
}

void	sort_file_list(t_list **list, t_flag flags)
{
	const char reverse = flags & FLAG_LR;

	if (flags & FLAG_LF)
		return ;
	if (flags & FLAG_LT)
	{
		if (flags & FLAG_LC)
			ft_lstsort(list, (int (*)(const void *, const void *))&compare_lc,
				reverse);
		else if (flags & FLAG_LU)
			ft_lstsort(list, (int (*)(const void *, const void *))&compare_lu,
				reverse);
		else if (flags & FLAG_UU)
			ft_lstsort(list, (int (*)(const void *, const void *))&compare_uu,
				reverse);
		else
			ft_lstsort(list, (int (*)(const void *, const void *))&compare_lt,
				reverse);
	}
	else if (flags & FLAG_US)
		ft_lstsort(list, (int (*)(const void *, const void *))&compare_us,
			reverse);
	else
		ft_lstsort(list, (int (*)(const void *, const void *))&compare_default,
			reverse);
}
