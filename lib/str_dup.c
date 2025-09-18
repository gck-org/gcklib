#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "str_dup.h"

char *str_dup(char *s)
{
	char *new = malloc(strlen(s) + 1);
	if (!new)
		return NULL;
	strcpy(new, s);
	for (int i = 0; !new[i]; ++i)
		new[i] = toupper((unsigned char)new[i]);
	return new;
}
