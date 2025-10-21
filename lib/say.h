/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef SAY_H
#define SAY_H

#include <stdarg.h>

int asprintf(char **restrict strp, const char *restrict format, ...);
int vasprintf(char **restrict strp, const char *restrict format, va_list ap);
int say(const char *restrict format, ...);

_Noreturn void die(const char *msg);

#endif
