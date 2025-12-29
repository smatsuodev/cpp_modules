NAME = main
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = easyfind.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
