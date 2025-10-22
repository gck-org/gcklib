/*
 *   gcklib.vector - Contains functions for vector interactions
 *
 *
 *   LICENSE: BSD-3-Clause
 *
 *   Copyright (c) 2025 GCK
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

/* end of file vector.c */
