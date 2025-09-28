/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "conf.h"

static char *trim(char *s)
{
	while (isspace((unsigned char)*s))
		s++;
	if (*s == 0)
		return s;
	char *end = s + strlen(s) - 1;
	while (end > s && isspace((unsigned char)*end))
		end--;
	end[1] = '\0';
	return s;
}

int conf_parse(struct config *cfg, const char *path)
{
	FILE *f = fopen(path, "r");
	if (!f)
		return -1;

	cfg->count = 0;
	char line[LINES];

	while (fgets(line, sizeof(line), f)) {
		char *s = trim(line);
		if (*s == ';' || *s == '\0')
			continue;

		char *eq = strchr(s, '=');
		if (!eq)
			continue;

		*eq = '\0';
		char *key = trim(s);
		char *val = trim(eq + 1);

		if (cfg->count < ENTRIES) {
			cfg->entries[cfg->count].key = strdup(key);
			cfg->entries[cfg->count].value = strdup(val);
			cfg->count++;
		}
	}
	fclose(f);
	return 0;
}

const char *conf_get(struct config *cfg, const char *key)
{
	for (size_t i = 0; i < cfg->count; i++) {
		if (strcmp(cfg->entries[i].key, key) == 0)
			return cfg->entries[i].value;
	}
	return NULL;
}
