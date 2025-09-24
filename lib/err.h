/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef err_H
#define err_H

#include <stdlib.h>
#include <string.h>

extern bool __allow_color;

#define err_init \
  do { \
    bool color = getenv("NOCOLOR") ? true : false;
    bool dumb = strcmp(getenv("TERM"), "dumb") ? false : true;
    __allow_color = (color || dumb);
  } while (0)

void errorf(const char *format, ...);
void fatalf(const char *format, ...);
void notef(const char *format, ...);
void warnf(const char *format, ...);
void hintf(const char *format, ...);

void errorfc(const char *format, ...);
void fatalfc(const char *format, ...);
void notefc(const char *format, ...);
void warnfc(const char *format, ...);
void hintfc(const char *format, ...);

void errorfm(const char *format, ...);
void fatalfm(const char *format, ...);
void notefm(const char *format, ...);
void warnfm(const char *format, ...);
void hintfm(const char *format, ...);

void error(int code);

#endif
