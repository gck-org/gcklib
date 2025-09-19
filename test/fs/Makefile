CC = gcc
CLFAGS = -Wall -Wextra -std=c23 -I../../lib

TEST = fs_test
SRCS = $(wildcard .)
OBJS = $(SRC:.c=.o)

all: $(TEST) 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(TEST)

.PHONY: all clean
