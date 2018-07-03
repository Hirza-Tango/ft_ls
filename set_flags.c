/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:24:06 by dslogrov          #+#    #+#             */
/*   Updated: 2018/07/03 13:55:27 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static t_flag	get_flag4(char flag)
{
	if (flag == 'W')
		return (FLAG_UW);
	else if (flag == 'w')
		return (FLAG_LW);
	else if (flag == 'x')
		return (FLAG_LX);
	else
		exit(1);
}

static t_flag	get_flag3(char flag)
{
	if (flag == 'P')
		return (FLAG_UP);
	else if (flag == 'p')
		return (FLAG_LP);
	else if (flag == 'q')
		return (FLAG_LQ);
	else if (flag == 'R')
		return (FLAG_UR);
	else if (flag == 'r')
		return (FLAG_LR);
	else if (flag == 'S')
		return (FLAG_US);
	else if (flag == 's')
		return (FLAG_LS);
	else if (flag == 'T')
		return (FLAG_UT);
	else if (flag == 't')
		return (FLAG_LT);
	else if (flag == 'u')
		return (FLAG_LU);
	else if (flag == 'U')
		return (FLAG_UU);
	else if (flag == 'v')
		return (FLAG_LV);
	return (get_flag4(flag));
}

static t_flag	get_flag2(char flag)
{
	if (flag == 'G')
		return (FLAG_UG);
	else if (flag == 'g')
		return (FLAG_LG);
	else if (flag == 'H')
		return (FLAG_UH);
	else if (flag == 'h')
		return (FLAG_LH);
	else if (flag == 'i')
		return (FLAG_LI);
	else if (flag == 'k')
		return (FLAG_LK);
	else if (flag == 'L')
		return (FLAG_UL);
	else if (flag == 'l')
		return (FLAG_LL);
	else if (flag == 'm')
		return (FLAG_LM);
	else if (flag == 'n')
		return (FLAG_LN);
	else if (flag == 'O')
		return (FLAG_UO);
	else if (flag == 'o')
		return (FLAG_LO);
	return (get_flag3(flag));
}

static t_flag	get_flag(char flag)
{
	if (flag == '@')
		return (FLAG_AT);
	else if (flag == '1')
		return (FLAG_1);
	else if (flag == 'A')
		return (FLAG_UA);
	else if (flag == 'a')
		return (FLAG_LA);
	else if (flag == 'B')
		return (FLAG_UB);
	else if (flag == 'b')
		return (FLAG_LB);
	else if (flag == 'C')
		return (FLAG_UC);
	else if (flag == 'c')
		return (FLAG_LC);
	else if (flag == 'd')
		return (FLAG_LD);
	else if (flag == 'e')
		return (FLAG_LE);
	else if (flag == 'F')
		return (FLAG_UF);
	else if (flag == 'f')
		return (FLAG_LF);
	return (get_flag2(flag));
}

void			set_flags(t_flag *settings, char flag)
{
	if (flag == '1' || flag == 'C' || flag == 'x' || flag == 'l')
		*settings &= ~FLAG_1 & ~FLAG_UC & ~FLAG_LX & ~FLAG_LL;
	else if (flag == 'c' || flag == 'u')
		*settings &= ~FLAG_LC & ~FLAG_LU;
	else if (flag == 'B' || flag == 'b' || flag == 'w' || flag == 'q')
		*settings &= ~FLAG_UB & ~FLAG_LB & ~FLAG_LW & ~FLAG_LQ;
	else if (flag == 'H' || flag == 'L' || flag == 'P')
		*settings &= ~FLAG_UH & ~FLAG_UL & ~FLAG_UP;
	if (flag == 'f')
		*settings |= FLAG_LA;
	if (flag == 'n' || flag == 'o')
		*settings |= FLAG_LL;
	*settings |= get_flag(flag);
}
