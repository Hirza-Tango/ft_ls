/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:11:18 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 14:45:36 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_error(const char *filename)
{
	ft_putstr_fd("ls: ", 2);
	if (!filename || errno == 13)
		ft_putstr_fd(": ", 2);
	if (errno != 13)
		perror(filename);
	else
		perror(NULL);
}
