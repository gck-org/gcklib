/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https:
 */

#include "say.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdarg.h>

int asprintf(char **restrict strp, const char *restrict format, ...)
{
	return 0;
}

int vasprintf(char **restrict strp, const char *restrict format, va_list ap)
{
	return 0;
}

int say(const char *restrict format, ...)
{
	struct winsize w;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
		va_list args;
		va_start(args, format);
		int ret = vprintf(format, args);
		va_end(args);
		putchar('\n');
		fflush(stdout);
		return ret;
	}

	printf("\0337"); // save cursor (ESC 7)
	printf("\033[%d;1H", w.ws_row); // move to last row
	printf("\033[2K"); // clear entire line

	va_list args;
	va_start(args, format);
	int ret = vprintf(format, args); // print formatted message
	va_end(args);

	fflush(stdout); // ensure it's visible immediately
	printf("\0338"); // restore cursor (ESC 8)
	fflush(stdout);

	return ret;
}

_Noreturn void die(const char *msg)
{
	fputs(msg, stderr);
	exit(EXIT_FAILURE);
}
