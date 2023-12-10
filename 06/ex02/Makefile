# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 00:25:26 by khbouych          #+#    #+#              #
#    Updated: 2023/12/11 00:46:04 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

S = main.cpp Base.cpp  A.cpp B.cpp C.cpp
H = Base.hpp A.hpp B.hpp C.hpp

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