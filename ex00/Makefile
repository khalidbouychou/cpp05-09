NAME = ex00

SRCS = main.cpp Bureaucrat.cpp

OBJCS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJCS)
	c++ -Wall -Wextra -Werror $(OBJCS) -o $(NAME)

all:$(NAME)

%.o : %.cpp Bureaucrat.hpp
	c++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJCS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re