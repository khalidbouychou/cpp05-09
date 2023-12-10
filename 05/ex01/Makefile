# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:15:27 by khbouych          #+#    #+#              #
#    Updated: 2023/12/08 17:42:35 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJCS = $(SRCS:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98
$(NAME) : $(OBJCS)
	c++ $(FLAGS) $(OBJCS) -o $(NAME)

all:$(NAME)

%.o : %.cpp Bureaucrat.hpp Form.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJCS)

fclean:clean
	@rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re