# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 23:37:36 by khbouych          #+#    #+#              #
#    Updated: 2023/12/21 17:43:16 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

git :
	@make fclean
	@git add .
	@git commit -m "auto commit"
	@git push

.PHONY: all clean fclean re