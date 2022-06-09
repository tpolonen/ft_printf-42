/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:57 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/09 19:39:54 by teppo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include "libft.h"

# include <stdio.h>

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
# define SIZE_T		524292
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

# define ALL_CAPS	8

# define F_STAR				1073741824
# define F_RIGHT_PADDING	536870912
# define F_PRINT_PLUS		268435456
# define F_PADDED_POS		134217728
# define F_ALT_FORM			67108864
# define F_PAD_WITH_ZEROES	33554432

# define CHAR_MASK	255
# define SHORT_MASK	65535
# define INT_MASK	4294967295

typedef struct s_token
{
	int		specs;
	int		width;
	int		precision;
	char	pad_char;
}	t_token;

typedef int	t_conv_function(t_token *token, va_list args);

typedef struct s_conv
{
	int				key;
	t_conv_function	*func;
}	t_conv;

int	ft_printf(const char *restrict format, ...)
	__attribute__ ((format (printf, 1, 2)));
int	dispatch(t_token *token, va_list args);
int	conv_integer(t_token *token, va_list args);
int	conv_char(t_token *token, va_list args);
int	conv_string(t_token *token, va_list args);
int	conv_float(t_token *token, va_list args);

int	print_prefix(int negative, t_token *token);
int	print_padding(int count, t_token *token, va_list args);
int	putnum(size_t num, int base, int min_len, int all_caps);
#endif
