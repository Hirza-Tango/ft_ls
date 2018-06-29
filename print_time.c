/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:23:34 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/29 12:18:14 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int	get_time_difference(time_t then)
{
	const time_t	now = time(NULL);

	if (now - (time_t)60 * 60 * 24 * 30.42 * 6 > then)
		return (1);
	return (0);
}

void		print_time(time_t secs)
{
	const char	*str = ctime(&secs);

	ft_printf(" %.2s", str + 8);
	ft_printf(" %.3s", str + 4);
	if (get_time_difference(secs))
		ft_printf("  %.4s", str + 20);
	else
		ft_printf(" %.5s", str + 11);
}
