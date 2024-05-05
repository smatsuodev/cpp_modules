NAME = RPN
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)

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
