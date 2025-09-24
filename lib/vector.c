/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <string.h>
#include "err.h"

#include "vector.h"

vec_t vec_init(size_t esz)
{
	vec_t v = { 0 };
	v.esz = esz;
	return v;
}

void vec_free(vec_t *v)
{
	if (!v)
		return;

	free(v->data);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}

void *vec_get(vec_t *v, size_t i)
{
	if (i >= v->len)
		return NULL;
	return (char *)v->data + i * v->esz;
}

void vec_set(vec_t *v, size_t i, void *elem)
{
	if (i >= v->len) {
		fatalf("out of bounds: index %d out of %d", i, v->len);
	}
	memcpy((char *)v->data + i * v->esz, elem, v->esz);
}

int vec_push(vec_t *v, void *elem)
{
}

int vec_pop(vec_t *v, void *out)
{
}

int vec_append(vec_t *v, size_t i, void *elem)
{
}

int vec_remove(vec_t *v, size_t i)
{
}
