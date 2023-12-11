# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:15:53 by khbouych          #+#    #+#              #
#    Updated: 2023/12/11 09:36:55 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

S = main.cpp
H = whatever.hpp

O = $(S:.cpp=.o)

all: $(NAME)

$(NAME): $(O)
	c++ -Wall -Wextra -Werror $(O) -o $(NAME)

%.o: %.cpp $(H)
	c++ -Wall -Wextra -Werror   -c $< -o $@

clean:
	@rm -rf $(O)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re