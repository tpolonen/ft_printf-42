# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 17:51:00 by tpolonen          #+#    #+#              #
#    Updated: 2022/07/25 18:45:10 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR		:= ./include/
SRC_DIR			:= ./src/
OBJ_DIR			:= ./obj/

_SRC	:= ft_printf.c
_SRC	+= conv_float.c
_SRC	+= conv_int.c
_SRC	+= dispatch.c
_SRC	+= float_utils.c
_SRC	+= notations.c
_SRC	+= write.c

_LFT	:= ft_abs.c
_LFT	+= ft_fabs.c
_LFT	+= ft_intlen.c
_LFT	+= ft_isdigit.c
_LFT	+= ft_isspace.c
_LFT	+= ft_max.c
_LFT	+= ft_memset.c
_LFT	+= ft_putchar.c
_LFT	+= ft_putnum.c
_LFT	+= ft_putset.c
_LFT	+= ft_strlen.c
_LFT	+= ft_strncmp.c
_LFT	+= ft_strtol.c

SRC		:= $(addprefix $(SRC_DIR), $(_SRC))
SRC		+= $(addprefix $(SRC_DIR), $(_LFT))
OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC			:= gcc
CFLAGS		:= -c -Wall -Wextra -Werror
CPPFLAGS	:= -I$(HEADER_DIR)
ARFLAGS		:= rcs

NAME	:= libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Compiled objs"
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@echo "Linked libftprintf.a"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ 

$(OBJ_DIR):
	@/bin/mkdir -p $@
	@echo "Made obj dir"

clean:
	@if [ -d "$(OBJ_DIR)" ]; \
		then /bin/rm -rf $(OBJ_DIR); echo "Removed objs"; fi

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Removed libftprintf.a"

re: fclean all
