/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause license.
 * <https://opensource.org/licenses/BSD-3-Clause>
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
#define HINT "\e[38;5;166m"

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

void hintf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fputs("hint: ", stderr);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void errorfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%serror%s: ", ERROR, RESET);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void fatalfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%sfatal%s: ", ERROR, RESET);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
	exit(EXIT_FAILURE);
}

void notefc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%snote%s: ", NOTE, RESET);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void warnfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%swarning%s: ", WARN, RESET);
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
}

void hintfc(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "%shint: ", HINT);
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n%s", RESET);
	va_end(args);
}

void errorfm(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (__allow_color) {
		errorfc(format, args);
	} else {
		errorf(format, args);
	}
	
	va_end(args);
}

void fatalfm(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (__allow_color) {
		fatalfc(format, args);
	} else {
		fatalf(format, args);
	}
	
	va_end(args);
}

void notefm(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (__allow_color) {
		notefc(format, args);
	} else {
		notef(format, args);
	}
	
	va_end(args);
}

void warnfm(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (__allow_color) {
		warnfc(format, args);
	} else {
		warnf(format, args);
	}
	
	va_end(args);
}

void hintfm(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (__allow_color) {
		hintf(format, args);
	} else {
		hintfc(format, args);
	}
	
	va_end(args);
}

void error(int code)
{
	errorf(strerror(code));
}
