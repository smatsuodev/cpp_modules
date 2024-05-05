NAME = main
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Array.hpp
	c++ $(CXXFLAGS) -o $@ $(OBJS)

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

.PHONY: all clean
