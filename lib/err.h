/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef err_H
#define err_H

void errorf(const char *format, ...);
void fatalf(const char *format, ...);
void notef(const char *format, ...);
void warnf(const char *format, ...);

void errorfc(const char *format, ...);
void fatalfc(const char *format, ...);
void notefc(const char *format, ...);
void warnfc(const char *format, ...);

void error(int code);

#endif
