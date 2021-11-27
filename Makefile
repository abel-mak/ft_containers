# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 17:10:37 by abel-mak          #+#    #+#              #
#    Updated: 2021/11/24 17:57:41 by abel-mak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft

NAME_DEBUG=ft_debug

SRC=main.cpp 

TEST2_SRC:=$(wildcard ./test/_test*.cpp)

TEST2_OUT=ft_test2

DOCTEST= ./test/doctest/doctest/

OBJ= $(SRC:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

HDR=$(wildcard ./src/*.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR) 
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

test2: $(TEST2_SRC)
	@clang++ $(FLAGS) $(TEST2_SRC) -o $(TEST2_OUT) && ./$(TEST2_OUT)
clean:
	rm -f $(NAME) $(TEST2_OUT) $(NAME_DEBUG) a.out
