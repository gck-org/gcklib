/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <string.h>

#include "vector.h"

vec_t vec_init(size_t esz)
{
	vec_t v;
	v.data = NULL;
	v.len = 0;
	v.cap = 0;
	v.esz = esz;
	return v;
}

void vec_free(vec_t *v)
{
	free(v->data);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
	v->esz = 0;
}

void *vec_get(vec_t *v, size_t i)
{
	if (i >= v->len)
		return NULL;
	return (char *)v->data + i * v->esz;
}

int vec_set(vec_t *v, size_t i, void *elem)
{
	if (i >= v->len)
		return -1;
	memcpy((char *)v->data + i * v->esz, elem, v->esz);
	return 0;
}

int vec_append(vec_t *v, void *elem)
{
	if (v->len == v->cap) {
		size_t newcap = v->cap ? v->cap * 2 : 4;
		void *newdata = realloc(v->data, newcap * v->esz);
		if (!newdata)
			return -1;
		v->data = newdata;
		v->cap = newcap;
	}
	memcpy((char *)v->data + v->len * v->esz, elem, v->esz);
	v->len++;
	return 0;
}

int vec_remove(vec_t *v)
{
	if (v->len == 0)
		return -1;
	v->len--;
	return 0;
}
