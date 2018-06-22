/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/22 17:12:51 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	main(int argc, char const *argv[])
{
	t_flag			flags;
	short int		current;
	char			*argument;

	if (argc < 2)
		return (1);
	current = 1;
	if (*argv[1] == '-')
	{
		argument = (char *)argv[1];
		while (*++argument)
			set_flags(&flags, *argument);
		current++;
	}
	if (current == argc - 1)
		ft_ls(argv[current], flags);
	else
		while (current < argc)
		{
			ft_printf("%s:\n", argv[current]);
			ft_ls(argv[current++], flags);
			if (current != argc - 1)
				ft_printf("\n");
		}
	return (0);
}
