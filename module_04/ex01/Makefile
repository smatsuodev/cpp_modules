NAME = main
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) -o $@ $^

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

re: clean all

.PHONY: all clean
