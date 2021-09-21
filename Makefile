# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 17:10:37 by abel-mak          #+#    #+#              #
#    Updated: 2021/09/21 13:43:01 by abel-mak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft

SRC=main.cpp 

TEST_SRC:=$(wildcard ./test/test*.cpp)

TEST_OUT=ft_test

DOCTEST= ./test/doctest/doctest/

OBJ= $(SRC:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

HDR=$(wildcard ./src/*.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR) 
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

test1: $(TEST_SRC) 
	clang++ -std=c++11 $(TEST_SRC) -o $(TEST_OUT) && ./$(TEST_OUT)

clean:
	rm -f $(NAME) $(TEST_OUT)

#NAME=
#
#SRC= 
#
#OBJ= $(SRC:.cpp=.o)
#
#FLAGS= -Wall -Wextra -Werror
#
#HDR=
#
#all:
#
#$(NAME): $(OBJ)
#
#%.o:%.cpp $(HDR)
#
#clean:
#
#fclean: clean
#
#re: fclean all

