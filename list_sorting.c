/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:55:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/23 10:25:05 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare_default(const t_file_info *a, const t_file_info *b)
{
	return (ft_strcmp(a->name, b->name));
}

t_list	*sort_file_list(t_list *lst, t_flag flags)
{
	const char rev = flags & FLAG_LR;

	if (flags & FLAG_LF)
		return (lst);
	if (flags & FLAG_LT)
	{
		if (flags & FLAG_LC)
			ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_lc,
				rev);
		else if (flags & FLAG_LU)
			ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_lu,
				rev);
		else if (flags & FLAG_UU)
			ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_uu,
				rev);
		else
			ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_lt,
				rev);
	}
	else if (flags & FLAG_US)
		ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_us, rev);
	else
		ft_lstsort(&lst, (long (*)(const void *, const void *))&compare_default,
			rev);
	return (lst);
}
