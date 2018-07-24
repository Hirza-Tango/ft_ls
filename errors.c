/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:11:18 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/24 17:15:43 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_error(const char *filename)
{
	ft_printf("ls: ");
	if (!filename || errno == 13)
		ft_printf(": ");
	if (errno != 13)
		perror(filename);
	else
		perror(NULL);
}
