/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:24:06 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/21 18:26:54 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	set_flags(int *flags, char flag)
{
	if (flag == 'l' || flag == 'C' || flag == 'x' || flag == 'l')
	{
		*flags &= ~FLAG_VALUE("l") & ~FLAG_VALUE("C") & ~FLAG_VALUE("x");
		*flags &= ~FLAG_VALUE("l");
	}
	else if (flag == 'c' || flag == 'u')
		*flags &= ~FLAG_VALUE("c") & ~FLAG_VALUE("u");
	else if (flag == 'B' || flag == 'b' || flag == 'w' || flag == 'q')
	{
		*flags &= ~FLAG_VALUE("B") & ~FLAG_VALUE("b") & ~FLAG_VALUE("W");
		*flags &= ~FLAG_VALUE("q");
	}
	*flags |= FLAG_VALUE(&flag);
}