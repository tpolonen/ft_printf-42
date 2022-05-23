/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:57 by tpolonen          #+#    #+#             */
/*   Updated: 2022/05/23 13:45:57 by tpolonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarh.h>

# include "libft.h"
# include "libftprint.h"

const char	g_flags[] = "-+ #0";
const char	*g_length[] = {
	"hh",
	"h",
	"l",
	"ll",
	"j",
	"z",
	"t",
	"L"
};

int	ft_printf(const char *restrict format, ...);

#endif
