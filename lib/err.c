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

#ifndef NOCOLOR
#define instance                                         \
	do {                                                 \
		if (__instanced) break;                          \
		bool nocolor = getenv("NOCOLOR") != NULL;        \
		const char *term = getenv("TERM");               \
		bool dumb = (term && strcmp(term, "dumb") == 0); \
		__allow_color = !(nocolor || dumb);              \
		__instacned = true;                              \
	} while (0)
#else
#define instance do {} while (0)
#endif

bool __instanced = false;
bool __allow_color = false;

void errorf(const char *format, ...)
{
	instance;
	
	va_list args;
	va_start(args, format);

	if (__allowed_color) {
		fprintf(stderr, "%serror%s: ", ERROR, RESET);
	} else {
		fputs("error: ", stderr);
	}
	
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}
void fatalf(const char *format, ...)
{
	instance;
	
	va_list args;
	va_start(args, format);

	if (__allowed_color) {
		fprintf(stderr, "%sfatal%s: ", ERROR, RESET);
	} else {
		fputs("fatal: ", stderr);
	}
	
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);

	exit(EXIT_FAILURE);
}
void warnf(const char *format, ...)
{
	instance;
	
	va_list args;
	va_start(args, format);

	if (__allowed_color) {
		fprintf(stderr, "%swarning%s: ", WARN, RESET);
	} else {
		fputs("warning: ", stderr);
	}
	
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}
void notef(const char *format, ...)
{
	instance;
	
	va_list args;
	va_start(args, format);

	if (__allowed_color) {
		fprintf(stderr, "%snote%s: ", NOTE, RESET);
	} else {
		fputs("note: ", stderr);
	}
	
	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);
}
void hintf(const char *format, ...)
{
	instance;
	
	va_list args;
	va_start(args, format);

	if (__allowed_color) {
		fprintf(stderr, "%shint: ", HINT, RESET);
	} else {
		fputs("hint: ", stderr);
	}
	
	vfprintf(stderr, format, args);

	if (__allowed_color) {
		fprintf(stderr, "%s\n", RESET);
	} else {
		fputc('\n', stderr);
	}

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
