# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:30:39 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/24 17:51:34 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERDIR1	:= ../include/
HEADERDIR2	:= ../../libft/include/
LFTDIR		:= ../../libft/

DEP := $(HEADERDIR1)ft_printf.h
DEP += $(HEADERDIR2)libft.h

SRC := $(wildcard ./*.c)
BIN := $(basename $(SRC))

CC			:= gcc
CFLAGS		:= -g -Wall -Wextra -Werror
CPPFLAGS	:= -I$(HEADER_DIR1) -I$(HEADER_DIR2)
LDFLAGS		:= -L$(LFTDIR)
LDLIBS		:= -lft

all: $(BIN)

$(BIN):
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC) $< -o $@
