/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:57 by tpolonen          #+#    #+#             */
/*   Updated: 2022/06/01 16:31:25 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"

typedef enum ftype
{
	INT,
	CHAR,
	FLOAT
}	t_ftype;

int	ft_printf(const char *restrict format, ...)
	__attribute__ ((format (printf, 1, 2)));

#endif
