# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-mak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 17:10:37 by abel-mak          #+#    #+#              #
#    Updated: 2021/09/13 12:28:25 by abel-mak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test

SRC=main.cpp 

OBJ= $(SRC:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

HDR=vector.hpp

all: $(NAME)

$(NAME): $(addprefix src/, $(HDR))
	clang++ $(FLAGS) $(SRC) 


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

