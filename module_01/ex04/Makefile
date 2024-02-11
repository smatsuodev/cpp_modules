NAME = replace
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) -o $@ $^

test: tests/test.cpp $(NAME)
	c++ -o $@ tests/test.cpp
	./test

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

.PHONY: all clean test
