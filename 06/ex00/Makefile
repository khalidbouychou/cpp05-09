# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 21:38:34 by khbouych          #+#    #+#              #
#    Updated: 2023/12/10 02:10:16 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ex00

S= main.cpp convert.cpp exec_type.cpp outil_convert.cpp to_type.cpp

H= convert.hpp

O= $(S:.cpp=.o)

F= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(O)
	c++ $(F) $(O) -o $(NAME)

%.o: %.cpp $(H)
	c++ $(F) -c $< -o $@

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re