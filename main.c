/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/25 16:29:29 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	main(int argc, char *argv[])
{
	t_flag			flags;
	char			*argument;

	(void)(argv++ && argc);
	flags = 0;
	while (*argv && **argv == '-' && argv[0][1])
	{
		argument = *(argv++);
		while (*++argument)
			set_flags(&flags, *argument);
	}
	if (!*argv)
		ft_ls(".", flags);
	else if (!argv[1])
		ft_ls(*argv, flags);
	else
		while (*argv)
		{
			ft_printf("%s:\n", *argv);
			ft_ls(*(argv++), flags);
			if (*argv)
				ft_putchar('\n');
		}
	return (errno ? 1 : 0);
}
