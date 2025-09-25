TESTEE = proginfo
MODDEPS = proginfo

CC = gcc
CFLAGS = -Wall -Wextra -I../../lib -g --std=c23 -I.
_MODDEPS = $(addprefix ../../lib/,$(addsuffix .c,$(MODDEPS)))

all: $(TESTEE)

$(TESTEE): $(TESTEE)_test.c $(_MODDEPS)
	$(CC) $(CFLAGS) $(_MODDEPS) $(TESTEE)_test.c -o $(TESTEE) -DCOMMIT=$(shell git rev-list --count --all)

clean:
	rm -f $(TESTEE)

.PHONY: all clean
