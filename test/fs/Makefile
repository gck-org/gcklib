CC = gcc
CFLAGS = -Wall -Wextra -I../../lib -g --std=c23
LDLIBS =

LIBSRC = ../../lib/fs.c ../../lib/str_dup.c
LIBOBJ = $(LIBSRC:.c=.o)

TESTSRC = fs_test.c
TESTOBJ = $(TESTSRC:.c=.o)

TARGET = fs_test

all: $(TARGET)

$(TARGET): $(TESTOBJ) $(LIBOBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(TARGET) $(TESTOBJ) $(LIBOBJ)

.PHONY: all clean
