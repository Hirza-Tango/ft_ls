/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:24:11 by dslogrov          #+#    #+#             */
/*   Updated: 2018/06/21 18:32:30 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

//# include <libft.h>
//# include <ft_printf.h>

# define FLAG_VALUE( a ) FLAG_ ## a 

# define FLAG_l (1 << 0)
# define FLAG_R (1 << 1)
# define FLAG_a (1 << 2)
# define FLAG_r (1 << 3)
# define FLAG_t (1 << 4)

# define FLAG_u (1 << 5)
# define FLAG_f (1 << 6)
# define FLAG_g (1 << 7)
# define FLAG_d (1 << 8)
# define FLAG_G (1 << 9)
# define FLAG_1 (1 << 10)
# define FLAG_C (1 << 11)
# define FLAG_e (1 << 12)
# define FLAG_at (1 << 13)

#endif
