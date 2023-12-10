# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:16:13 by khbouych          #+#    #+#              #
#    Updated: 2023/12/08 17:30:15 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRCS = main.cpp Bureaucrat.cpp

OBJCS = $(SRCS:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJCS)
	c++ $(FLAGS) $(OBJCS) -o $(NAME)

all:$(NAME)

%.o : %.cpp Bureaucrat.hpp
	c++ $(FLAGS)  -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re