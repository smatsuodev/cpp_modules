NAME = harlFilter
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $@ $^

%.o: %.cpp
	c++ -c $< -o $@

clean:
	-$(RM) $(OBJS)
	-$(RM) $(NAME)

.PHONY: all clean
