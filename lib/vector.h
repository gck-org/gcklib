/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
	void *data;
	size_t len;
	size_t cap;
	size_t esz;
} vec_t;

vec_t vec_init(size_t esz);
void vec_free(vec_t *v);

void *vec_get(vec_t *v, size_t i);
int vec_set(vec_t *v, size_t i, void *elem);

int vec_append(vec_t *v, void *elem);
int vec_remove(vec_t *v);

#endif
