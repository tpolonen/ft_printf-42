# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:30:39 by tpolonen          #+#    #+#              #
#    Updated: 2022/07/02 20:45:26 by tpolonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERDIR1	:= ../include/
HEADERDIR2	:= ../../libft/include/

DEP := $(HEADERDIR1)ft_printf.h
DEP += $(HEADERDIR2)libft.h

SRC1 := $(wildcard ./*.c)
BIN := $(basename $(SRC1))

CC			:= gcc
CFLAGS		:= -g
CPPFLAGS	:= -I$(HEADERDIR1) -I$(HEADERDIR2)
LDFLAGS		:= -L../
LDLIBS		:= -lftprintf

all: $(BIN)

lib:
	make -C ../

%: %.c lib
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@.out $(LDFLAGS) $(LDLIBS)

clean:
	/bin/rm -rf *.out

re: clean
	make all
