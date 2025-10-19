/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef ERR_H
#define ERR_H

void errorf(const char *format, ...);
_Noreturn void fatalf(const char *format, ...);
void notef(const char *format, ...);
void warnf(const char *format, ...);
void hintf(const char *format, ...);

void errorfa(int code);
_Noreturn void fatalfa(int code);
void notefa(int code);
void warnfa(int code);
void hintfa(int code);

void gcklib_error(int status, int errnum, const char *format, ...);
#ifndef GCKLIB_DISABLE_SHORT
#define error(status, code, fmt, ...) \
	gcklib_error(status, code, fmt, __VA_ARGS__)
#endif

#endif
