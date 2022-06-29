# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:50:42 by tpolonen          #+#    #+#              #
#    Updated: 2022/06/29 21:58:03 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR 		:= ./include/
LFTHEADER_DIR	:= ../libft/include/
LFT_DIR			:= ../libft/
SRC_DIR 		:= ./src/
OBJ_DIR 		:= ./obj/

_SRC := $(notdir $(wildcard $(SRC_DIR)*.c))

DEP := $(HEADER_DIR)ft_printf.h
DEP += $(LFTHEADER_DIR)libft.h

NAME := libftprintf.a

SRC  		:= $(addprefix $(SRC_DIR), $(_SRC))
OBJ  		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
LIBFT		:= $(addprefix $(LFT_DIR), libft.a)
LIBFT_OBJ 	:= $(wildcard $(LFT_DIR)obj/*.c)

CC 		 := clang
CFLAGS 	 := -c -g -Wall -Wextra -Werror -Wconversion
CPPFLAGS := -I$(LFTHEADER_DIR) -I$(HEADER_DIR)
LDFLAGS  := -L$(LFT_DIR)
LDLIBS   := -lft
ARFLAGS  := rcs

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C $(LFT_DIR) all

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo "Compiled libftprintf objs"
	@$(AR) $(ARFLAGS) $(@) $(OBJ) $(LIBFT_OBJ)
	@echo "Compiled libftprintf.a"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "Cleaned libftprintf objs"
	@make -C $(LFT_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Removed libftprintf.a"
	@make -C $(LFT_DIR) fclean

re: fclean all

