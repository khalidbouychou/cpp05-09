# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:17:02 by khbouych          #+#    #+#              #
#    Updated: 2023/12/08 18:18:34 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

HPP = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

OBJCS = $(SRCS:.cpp=.o)

F= -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJCS)
	c++ $(F) $(OBJCS) -o $(NAME)

all:$(NAME)

%.o : %.cpp $(HPP)
	c++ $(F) -c $< -o $@

clean:
	@rm -rf $(OBJCS)

fclean:clean
	@rm -rf $(NAME) *_shrubbery

re:fclean all

.PHONY: all clean fclean re