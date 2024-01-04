NAME = replace
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $@ $^

test: tests/test.cpp $(NAME)
	c++ -o $@ tests/test.cpp
	./test

%.o: %.cpp
	c++ -c $< -o $@

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

.PHONY: all clean test
