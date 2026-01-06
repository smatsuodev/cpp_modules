NAME = RPN
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g -fsanitize=address
CXX = c++

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
