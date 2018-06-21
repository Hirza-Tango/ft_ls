/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/21 17:27:40 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int main(int argc, char const *argv[])
{
	short int	flags;
	short int	current;

	if (argc < 2)
		return (1);
	current = 1;
	if (*argv[1] == '-')
	{
		while (*++argv[1])
			set_flags(&flags, *argv[1]);
		current++;
	}
	if (current == argc - 1)
		ft_ls(argv[current], flags);
	else
		while (current < argc)
		{
			ft_printf("%s:\n", argv[current], flags);
			ft_ls(argv[current++], flags);
			if (current != argc - 1)
				ft_printf("\n");
		}
	return (0);
}
