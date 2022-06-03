/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:57 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/03 11:59:23 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"

/* Here starts defining of bitmasks.
 * Each following decimal number is used as bitmask for interpreting the token.
 */

# define INTEGER	49340
# define S_DEC 		49152
# define U_DEC 		32
# define U_OCT 		128
# define U_HEX 		24
# define PTR 		4
# define SHORT		16777216
# define S_CHAR		8388608
# define LONG		4194304
# define LLONG 		2097152
# define INTMAX_T	1048576
# define SIZE_T		524288
# define PTRDIFF_T	262144

# define CHAR		65601
# define U_CHAR		65536
# define CHAR_ARR	64
# define PERCENT	1

# define FLOAT		16128
# define LDOUBLE	131072
# define SCI_DOUBLE 12288
# define DEC_DOUBLE 3072 
# define SHORTEST_F 768	

# define SIGNED		311296
# define UNSIGNED	65724
# define DECIMAL	49184
# define OCTAL		128
# define HEXAL		28

typedef struct s_token
{
	int	specs;
	int	width;
	int	precision;
}	t_token;

int	ft_printf(const char *restrict format, ...) 
		__attribute__ ((format (printf, 1, 2)));
int	int_handler(t_dstr **out, int token, va_list args);
int	char_handler(t_dstr **out, int token, va_list args);
int float_handler(t_dstr **out, int token, va_list args);

#endif
