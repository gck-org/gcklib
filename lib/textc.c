#include <string.h>
#include <ctype.h>
#include "xmem.h"

#include "textc.h"

char *str_dup(char *s)
{
	char *new = xmalloc(strlen(s) + 1);
	strcpy(new, s);
	return new;
}

char *tostrupr(char *s)
{
	char *new = str_dup(s);
	for (int i = 0; new[i] != '\0'; ++i)
		new[i] = toupper((unsigned char)new[i]);
	return new;
}

char *tostrlwr(char *s)
{
	char *new = str_dup(s);
	for (int i = 0; new[i] != '\0'; ++i)
		new[i] = tolower((unsigned char)new[i]);
	return new;
}

char *textc_trim(char *s)
{
	return NULL;
}

char *textc_pad_left(int count, char *s, char pad)
{
	char *buffer = xmalloc(strlen(s) + 1);

	free(buffer);
	buffer = "NOT IMPLEMENTED";

	return buffer;
}
