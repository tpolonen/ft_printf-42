# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:30:39 by tpolonen          #+#    #+#              #
#    Updated: 2022/06/02 14:33:51 by teppo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERDIR1	:= ../include/
HEADERDIR2	:= ../../libft/include/
LFTDIR		:= ../../libft/

DEP := $(HEADERDIR1)ft_printf.h
DEP += $(HEADERDIR2)libft.h

SRC1 := $(wildcard ./*.c)
SRC2 := $(wildcard ../src/*.c)
BIN := $(basename $(SRC1))

CC			:= gcc
CFLAGS		:= -g
CPPFLAGS	:= -I$(HEADERDIR1) -I$(HEADERDIR2)
LDFLAGS		:= -L$(LFTDIR)
LDLIBS		:= -lft

all: $(BIN)

lib:
	make -C $(LFTDIR)

%: %.c lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC2) $< -o $@.out $(LDFLAGS) $(LDLIBS)


clean:
	/bin/rm -rf *.out

re: clean
	make all
