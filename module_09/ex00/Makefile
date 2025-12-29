NAME = btc
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
CXX = c++

SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS) $(DEPS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
