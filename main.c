/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/29 17:24:29 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	main(int argc, char const *argv[])
{
	t_flag			flags;
	short int		current;
	char			*argument;

	current = 1;
	flags = 0;
	while (*argv[current] == '-' && current < argc)
	{
		argument = (char *)argv[current];
		while (*++argument)
			set_flags(&flags, *argument);
		current++;
	}
	if (current == argc)
		ft_ls(".", flags);
	else if (current == argc - 1)
		ft_ls(argv[current], flags);
	else
		while (current < argc)
		{
			ft_printf("%s:\n", argv[current]);
			ft_ls(argv[current], flags);
			if (current++ == argc - 1)
				ft_printf("\n");
		}
	return (0);
}
