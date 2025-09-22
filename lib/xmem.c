/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <stdio.h>
#include <stdlib.h>

#include "xmem.h"

void *xmalloc(size_t size)
{
	void *ptr;

	if (size == 0)
		return NULL;

	ptr = malloc(size);
	if (ptr == NULL) {
		fprintf(stderr, "xmalloc: memory exhausted\n", size);
		exit(EXIT_FAILURE);
	}

	return ptr;
}

void *xrealloc(void *ptr, size_t size)
{
	void *newptr;

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	newptr = realloc(ptr, size);
	if (newptr == NULL) {
		fprintf(stderr, "xrealloc: memory exhausted\n");
		exit(EXIT_FAILURE);
	}

	return newptr;
}

void *xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return NULL;

	ptr = calloc(nmemb, size);
	if (ptr == NULL) {
		fprintf(stderr, "xcalloc: memory exhausted\n");
		exit(EXIT_FAILURE);
	}

	return ptr;
}
