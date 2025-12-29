NAME = main
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) whatever.hpp
	c++ $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
