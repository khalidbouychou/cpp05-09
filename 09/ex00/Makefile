# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 02:43:40 by khbouych          #+#    #+#              #
#    Updated: 2023/12/17 02:04:36 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp BitcoinExchange.cpp outils.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re