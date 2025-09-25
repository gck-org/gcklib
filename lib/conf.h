/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#ifndef CONF_H
#define CONF_H

#include <stddef.h>

#ifndef ENTRIES
#define ENTRIES 128
#endif

#ifndef LINES
#define LINES 256
#endif

struct entry {
	char *key;
	char *value;
};

struct config {
	struct entry entries[ENTRIES];
	size_t count;
};

int conf_parse(const char *path, struct config *cfg);
const char *conf_get(struct config *cfg, const char *key);

#endif
