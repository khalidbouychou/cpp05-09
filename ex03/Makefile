# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:17:02 by khbouych          #+#    #+#              #
#    Updated: 2023/12/06 18:21:04 by khbouych         ###   ########.fr        #
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
git :
	make fclean
	git add .
	git commit -m "updatecpp ex02-05"
	git push
.PHONY: all clean fclean re