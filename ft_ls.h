/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:24:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/26 11:50:11 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_printf.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>

# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define FLAG_LL (t_flag)(1ULL << 0)
# define FLAG_UR (t_flag)(1ULL << 1)
# define FLAG_LA (t_flag)(1ULL << 2)
# define FLAG_LR (t_flag)(1ULL << 3)
# define FLAG_LT (t_flag)(1ULL << 4)

# define FLAG_LU (t_flag)(1ULL << 5)
# define FLAG_LF (t_flag)(1ULL << 6)
# define FLAG_LG (t_flag)(1ULL << 7)
# define FLAG_LD (t_flag)(1ULL << 8)
# define FLAG_UG (t_flag)(1ULL << 9)
# define FLAG_1  (t_flag)(1ULL << 10)
# define FLAG_UC (t_flag)(1ULL << 11)
# define FLAG_LE (t_flag)(1ULL << 12)
# define FLAG_AT (t_flag)(1ULL << 13)

# define FLAG_UA (t_flag)(1ULL << 14)
# define FLAG_UB (t_flag)(1ULL << 15)
# define FLAG_LB (t_flag)(1ULL << 16)
# define FLAG_LC (t_flag)(1ULL << 17)
# define FLAG_UF (t_flag)(1ULL << 18)
# define FLAG_UH (t_flag)(1ULL << 19)
# define FLAG_LH (t_flag)(1ULL << 20)
# define FLAG_LI (t_flag)(1ULL << 21)
# define FLAG_LK (t_flag)(1ULL << 22)
# define FLAG_UL (t_flag)(1ULL << 23)
# define FLAG_LM (t_flag)(1ULL << 24)
# define FLAG_LN (t_flag)(1ULL << 25)
# define FLAG_UO (t_flag)(1ULL << 26)
# define FLAG_LO (t_flag)(1ULL << 27)
# define FLAG_UP (t_flag)(1ULL << 28)
# define FLAG_LP (t_flag)(1ULL << 29)
# define FLAG_LQ (t_flag)(1ULL << 30)
# define FLAG_US (t_flag)(1ULL << 31)
# define FLAG_LS (t_flag)(1ULL << 32)
# define FLAG_UT (t_flag)(1ULL << 33)
# define FLAG_UU (t_flag)(1ULL << 34)
# define FLAG_LV (t_flag)(1ULL << 35)
# define FLAG_UW (t_flag)(1ULL << 36)
# define FLAG_LW (t_flag)(1ULL << 37)
# define FLAG_LX (t_flag)(1ULL << 38)

typedef __uint64_t	t_flag;

typedef struct		s_file_info
{
	char			*path;
	char			*name;
	struct stat		stat;
}					t_file_info;

typedef struct		s_ls_spacing
{
	size_t			links;
	size_t			passwd;
	size_t			group;
	size_t			size;
}					t_ls_spacing;

long				compare_default(const t_file_info *a, const t_file_info *b);
long				compare_lc(const t_file_info *a, const t_file_info *b);
long				compare_lu(const t_file_info *a, const t_file_info *b);
long				compare_uu(const t_file_info *a, const t_file_info *b);
long				compare_us(const t_file_info *a, const t_file_info *b);
long				compare_lt(const t_file_info *a, const t_file_info *b);

void				ls_print_normal(const t_list *list, t_flag flags);
void				ls_print_ll(const t_list *list, t_flag flags,
	int print_blocks);
void				ls_print_ll_one(t_file_info f, t_flag flags,
	t_ls_spacing space);
t_list				*sort_file_list(t_list *list, t_flag flags);
void				set_flags(t_flag *settings, char flag);
void				ft_ls(const char *location, t_flag flags);
void				print_permissions(mode_t mode);
void				print_time(struct stat s, t_flag flags);
void				ft_error(const char *filename);
char				get_type_print(mode_t mode);
int					fill_info(const char *name, const char *path,
	t_file_info *info);
void				ft_fileinfodel(void *info, size_t len);
#endif
