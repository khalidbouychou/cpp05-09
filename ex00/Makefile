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

git :
	make fclean
	git add .
	git commit -m "updatecpp ex00-05"
	git push

.PHONY: all clean fclean re