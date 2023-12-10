# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 20:58:31 by khbouych          #+#    #+#              #
#    Updated: 2023/12/10 23:48:39 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

S = main.cpp Serializer.cpp
H = Serializer.hpp

O = $(S:.cpp=.o)

all: $(NAME)

$(NAME): $(O)
	c++ -Wall -Wextra -Werror $(O) -o $(NAME)

%.o: %.cpp $(H)
	c++ -Wall -Wextra -Werror  -c $< -o $@

clean:
	@rm -rf $(O)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re