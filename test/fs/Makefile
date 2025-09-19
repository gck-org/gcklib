LIBFILES := $(wildcard ../lib/*)

.POSIX:
CC ::= gcc
CFLAGS ::= -Wall -Wextra --std=c23

all: fs_test

fs_test:
	$(CC) $(CFLAGS) -I../lib $(LIBFILES) fs_test.c -o fs_test

clean:
	$(RM) fs
