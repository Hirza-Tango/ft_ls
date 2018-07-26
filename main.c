/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:45:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 17:06:45 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	special_case(const char *dir, t_flag flags)
{
	char		buff[255];
	t_file_info	info;
	ssize_t		result;

	if (!(flags & FLAG_LL))
	{
		result = readlink(dir, buff, 255);
		buff[result] = 0;
		if (ft_isdir(buff) == 1)
			ft_ls(buff, flags);
		else
			ft_putendl(dir);
	}
	else
	{
		fill_info(dir, ft_strdup(dir), &info);
		ls_print_ll_one(info, flags, (t_ls_spacing){0, 0, 0, 0});
		free(info.name);
		free(info.path);
	}
}

void		dir_list(char **argv, t_flag flags, int printed)
{
	char		**dup;
	t_list		*lst;
	t_file_info	info;

	dup = argv;
	lst = NULL;
	while (*dup)
	{
		if (ft_isdir(*dup) == 1 && !fill_info(*dup, ft_strdup(*dup), &info))
			ft_lstappend(&lst, ft_lstnew(&info, sizeof(t_file_info)));
		dup++;
	}
	lst = sort_file_list(lst, flags);
	while (lst)
	{
		printed++ ? ft_putchar('\n') : (void)0;
		ft_printf("%s:\n", ((t_file_info *)lst->content)->name);
		ft_ls(((t_file_info *)lst->content)->name, flags);
		lst = lst->next;
	}
	ft_lstdel(&lst, ft_fileinfodel);
}

static int	file_list(char **argv, t_flag flags)
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

	(void)(argv++ && argc);
	flags = 0;
	while (*argv && **argv == '-' && argv[0][1])
	{
		if (!ft_strcmp(*argv, "--"))
		{
			argv++;
			break ;
		}
		argument = *(argv++);
		while (*++argument)
			set_flags(&flags, *argument);
	}
	if (!*argv)
		ft_ls(".", flags);
	else if (!argv[1] && ft_isdir(*argv) == 1)
		ft_ls(*argv, flags);
	else if (!argv[1] && ft_islnk(*argv) == 1)
		special_case(*argv, flags);
	else
		dir_list(argv, flags, file_list(argv, flags));
	return (errno ? 1 : 0);
}
