/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 14:05:55 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int	ft_isdir(const char *dir)
{
	struct stat	s;

	if (lstat(dir, &s))
		return (-1);
	if ((s.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

static int	entry_list(char **argv, t_flag flags)
{
	char		**dup;
	t_list		*lst;
	t_file_info	info;

	dup = argv;
	while (*dup)
	{
		if (!ft_isdir(*dup) && !fill_info(*dup, ft_strdup(*dup), &info))
			ft_lstappend(&lst, ft_lstnew(&info, sizeof(t_file_info)));
		else if (ft_isdir(*dup) == -1)
			ft_error(*dup);
		dup++;
	}
	lst = sort_file_list(lst, flags);
	if (flags & FLAG_LL)
		ls_print_ll(lst, flags, 0);
	else
		ls_print_norm(lst, flags);
	if (!lst)
		return (0);
	ft_lstdel(&lst, ft_fileinfodel);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_flag			flags;
	char			*argument;
	int				printed;

	(void)(argv++ && argc);
	flags = 0;
	while (*argv && **argv == '-' && argv[0][1])
	{
		argument = *(argv++);
		if (argument[1] == '-')
			break ;
		while (*++argument)
			set_flags(&flags, *argument);
	}
	if (!*argv)
		ft_ls(".", flags);
	else if (!argv[1] && ft_isdir(*argv) == 1)
		ft_ls(*argv, flags);
	else
	{
		printed = entry_list(argv, flags);
		while (*argv)
		{
			if (ft_isdir(*argv) == 1)
			{
				printed++ ? ft_putchar('\n') : (void)0;
				ft_printf("%s:\n", *argv);
				ft_ls(*(argv), flags);
			}
			argv++;
		}
	}
	return (errno ? 1 : 0);
}
