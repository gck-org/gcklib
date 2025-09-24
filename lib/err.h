/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef ERR_H
#define ERR_H

#include <stdlib.h>
#include <string.h>

extern bool __allow_color;

#define err_init                                                 \
	do {                                                     \
		bool nocolor = getenv("NOCOLOR") != NULL;        \
		const char *term = getenv("TERM");               \
		bool dumb = (term && strcmp(term, "dumb") == 0); \
		__allow_color = !(nocolor || dumb);              \
	} while (0)

void errorf(const char *format, ...);
void fatalf(const char *format, ...);
void notef(const char *format, ...);
void warnf(const char *format, ...);
void hintf(const char *format, ...);

void errorfa(int code);
void fatalfa(int code);
void notefa(int code);
void warnfa(int code);
void hintfa(int code);

#endif
