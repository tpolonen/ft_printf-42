# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:30:39 by tpolonen          #+#    #+#              #
#    Updated: 2022/05/31 19:16:42 by tpolonen         ###   ########.fr        #
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
CFLAGS		:= -g -Wall -Wextra -Werror
CPPFLAGS	:= -I$(HEADERDIR1) -I$(HEADERDIR2)
#$(addprefix -I,$(DEP))
LDFLAGS		:= -L$(LFTDIR)
LDLIBS		:= -lft

all: $(BIN)

$(BIN): $(SRC1) $(SRC2) $(DEP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC1) $(SRC2) -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf $(BIN)

re: clean
	make all
