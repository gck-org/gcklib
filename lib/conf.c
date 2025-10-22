/*
 *   gcklib.conf - Configuration file interactions
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

/* end of file conf.c */
