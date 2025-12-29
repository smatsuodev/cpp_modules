NAME = RPN
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = RPN.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
