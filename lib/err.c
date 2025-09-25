/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause license.
 * <https://opensource.org/licenses/BSD-3-Clause>
 */

#include <stdio.h>
#include <stdarg.h>

#include "err.h"

#define RESET "\e[0m"
#define ERROR "\e[1;91m"
#define WARN "\e[1;95m"
#define NOTE "\e[1;94m"
#define HINT "\e[38;5;166m"

bool __allow_color = false;

void errorf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

#ifdef NOCOLOR
	fputs("error: ", stderr);
#else
	fprintf(stderr, "%serror%s: ", ERROR, RESET);
#endif
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}

void fatalf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

#ifdef NOCOLOR
	fputs("error: ", stderr);
#else
	fprintf(stderr, "%serror%s: ", ERROR, RESET);
#endif
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);

	exit(EXIT_FAILURE);
}

void warnf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

#ifdef NOCOLOR
	fputs("warn: ", stderr);
#else
	fprintf(stderr, "%swarn%s: ", WARN, RESET);
#endif
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}

void notef(const char *format, ...)
{
	va_list args;
	va_start(args, format);

#ifdef NOCOLOR
	fputs("note: ", stderr);
#else
	fprintf(stderr, "%snote%s: ", NOTE, RESET);
#endif
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}

void hintf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

#ifdef NOCOLOR
	fputs("hint: ", stderr);
#else
	fprintf(stderr, "%shint: ", HINT);
#endif
	vfprintf(stderr, format, args);
	fprintf(stderr, "%s\n", RESET);

	va_end(args);
}

void errorfa(int code)
{
	errorf(strerror(code));
}

void fatalfa(int code)
{
	fatalf(strerror(code));
}

void notefa(int code)
{
	notef(strerror(code));
}

void warnfa(int code)
{
	warnf(strerror(code));
}

void hintfa(int code)
{
	hintf(strerror(code));
}
