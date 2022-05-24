# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 13:50:42 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/24 17:51:10 by tpolonen         ###   ########.fr        #
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
CFLAGS 	 := -c -Wall -Wextra -Werror -I$(HEADER_DIR)
CPPFLAGS := -I$(LFTHEADER_DIR) -I$(HEADER_DIR)
LDFLAGS  := -L$(LFT_DIR)
LDLIBS   := -lft -lftprintf
ARFLAGS  := rcs

.PHONY: all clean fclean re tests

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@/bin/rm -r $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re tests
