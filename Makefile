# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:50:42 by tpolonen          #+#    #+#              #
#    Updated: 2022/06/21 23:46:03 by teppo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER_DIR 		:= ./include/
LFTHEADER_DIR	:= ../libft/include/
LFT_DIR			:= ../libft/
SRC_DIR 		:= ./src/
OBJ_DIR 		:= ./obj/

DEP := $(HEADER_DIR)ft_printf.h
DEP += $(LFTHEADER_DIR)libft.h

NAME := libftprintf.a
SRC  := $(wildcard $(SRC_DIR)*.c)
OBJ  := $(patsubst $(SRC_DIR)%.c,  $(OBJ_DIR)%.o, $(SRC))

CC 		 := gcc
CFLAGS 	 := -c -g -Wall -Wextra -Werror -Wconversion
CPPFLAGS := -I$(LFTHEADER_DIR) -I$(HEADER_DIR)
LDFLAGS  := -L$(LFT_DIR)
LDLIBS   := -lft
ARFLAGS  := rcs

.PHONY: all lib clean fclean lclean lfclean re

all: $(NAME)

lib:
	make -C $(LFT_DIR) all

$(NAME): lib $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR):
	mkdir -p $@

lclean:
	make -C $(LFT_DIR) clean

clean: lclean
	@/bin/rm -rf $(OBJ_DIR)

lfclean:
	make -C $(LFT_DIR) fclean

fclean: clean lfclean
	/bin/rm -f $(NAME)

re: fclean all

