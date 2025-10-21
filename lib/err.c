/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause license.
 * <https://opensource.org/licenses/BSD-3-Clause>
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "err.h"

#include "proginfo.h"

#define RESET "\x1B[0m"
#define ERROR "\x1B[1;91m"
#define WARN "\x1B[1;95m"
#define NOTE "\x1B[1;94m"
#define HINT "\x1B[38;5;166m"

static bool err_support_color(void)
{
#ifdef NOCOLOR
	return false;
#else
	static int cached = -1;
	if (cached != -1)
		return cached;
	const char *term, *colorterm, *force, *nocolor;
	term = getenv("TERM");
	colorterm = getenv("COLORTERM");
	force = getenv("FORCE_COLOR");
	nocolor = getenv("NO_COLOR");
	if (nocolor && *nocolor && (!force || !*force)) {
		cached = 0;
		return false;
	}
	if (force && *force && strcmp(force, "0") != 0) {
		cached = 1;
		return true;
	}
	// if (!isatty(fileno(stdout))) {
	// 	cached = 0;
	// 	return false;
	// }
	if (colorterm && *colorterm) {
		cached = 1;
		return true;
	}
	if (!term || !*term) {
		cached = 0;
		return false;
	}
	if (strstr(term, "color") || strstr(term, "xterm") ||
	    strstr(term, "screen") || strstr(term, "vt100") ||
	    strstr(term, "rxvt") || strstr(term, "ansi") ||
	    strstr(term, "linux") || strstr(term, "konsole") ||
	    strstr(term, "vte") || strstr(term, "kitty") ||
	    strstr(term, "wezterm") || strstr(term, "gnome")) {
		cached = 1;
		return true;
	}
	cached = 0;
	return false;
#endif
}

void errorf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (err_support_color()) {
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
	va_list args;
	va_start(args, format);

	if (err_support_color()) {
		fprintf(stderr, "%sfatal error%s: ", ERROR, RESET);
	} else {
		fputs("fatal error: ", stderr);
	}

	vfprintf(stderr, format, args);
	fputc('\n', stderr);

	va_end(args);

	fputs("program terminated.\n", stderr);
	exit(EXIT_FAILURE);
}
void warnf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	if (err_support_color()) {
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
	va_list args;
	va_start(args, format);

	if (err_support_color()) {
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
	va_list args;
	va_start(args, format);

	if (err_support_color()) {
		fprintf(stderr, "%shint: ", HINT);
	} else {
		fputs("hint: ", stderr);
	}

	vfprintf(stderr, format, args);

	if (err_support_color()) {
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
