NAME = main
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#SRCS = $(wildcard *.cpp)
#OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): ScalarConverter.o main.o
	c++ $(CXXFLAGS) -o $@ $^

test: ScalarConverter.o test.o
	c++ $(CXXFLAGS) -o test $^

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

.PHONY: all clean
