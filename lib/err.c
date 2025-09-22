/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "err.h"

#define RESET "\e[0m"
#define ERROR "\e[1;91m"
#define WARN "\e[1;95m"
#define NOTE "\e[1;94m"

void errorf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fputs("error: ", stderr);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void fatalf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fputs("fatal: ", stderr);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
	exit(EXIT_FAILURE);
}

void notef(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fputs("note: ", stderr);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void warnf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fputs("warning: ", stderr);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void errorfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%serror%s: ", ERROR, RESET);
	fprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void fatalfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%sfatal%s: ", ERROR, RESET);
	fprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
	exit(EXIT_FAILURE);
}

void notefc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%snote%s: ", NOTE, RESET);
	fprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void warnfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%swarn%s: ", WARN, RESET);
	fprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void error(int code)
{
	errorf(strerror(code));
}
