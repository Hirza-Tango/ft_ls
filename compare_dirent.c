/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_dirent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:54:54 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/22 18:26:50 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		compare_default(const struct dirent a, const struct dirent b, const char * path)
{
	return (ft_strcmp(a.d_name, b.d_name));
}

int		compare_lc(const struct dirent a, const struct dirent b, const char * path)
{
	return (0);
}
int		compare_lu(const struct dirent a, const struct dirent b, const char * path)
{
	return (0);
}
int		compare_uu(const struct dirent a, const struct dirent b, const char * path)
{
	return (0);
}
int		compare_ut(const struct dirent a, const struct dirent b, const char * path)
{
	return (0);
}