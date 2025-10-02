TESTEE = textc
MODDEPS = textc err xmem

CC = gcc
CFLAGS = -Wall -Wextra -I../../lib -g --std=c23
_MODDEPS = $(addprefix ../../lib/,$(addsuffix .c,$(MODDEPS)))

all: $(TESTEE)

$(TESTEE): $(TESTEE)_test.c $(_MODDEPS)
	$(CC) $(CFLAGS) $(_MODDEPS) $(TESTEE)_test.c -o $(TESTEE)

clean:
	rm -f $(TESTEE)

.PHONY: all clean
