/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:11:18 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/04 11:43:20 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	error(const char *filename)
{
	ft_printf("ls: ");
	if (!filename)
		ft_printf(": ");
	perror(filename);
}
