/* Copyright (C) GCK
 *
 * This file is part of gcklib
 *
 * This project and file is licensed under the BSD-3-Clause licence.
 * <https://opensource.org/licence/bsd-3-clause>
 */

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "fs.h"

char *fs_read(const char *path)
{
	FILE *f;
	long size;
	char *buf;

	f = fopen(path, "rb");
	if (!f)
		return NULL;

	if (fseek(f, 0, SEEK_END) != 0) {
		fclose(f);
		return NULL;
	}

	size = ftell(f);
	if (size < 0) {
		fclose(f);
		return NULL;
	}

	if (fseek(f, 0, SEEK_SET) != 0) {
		fclose(f);
		return NULL;
	}

	buf = malloc(size + 1);
	if (!buf) {
		fclose(f);
		return NULL;
	}

	if (fread(buf, 1, size, f) != (size_t)size) {
		free(buf);
		fclose(f);
		return NULL;
	}

	buf[size] = '\0';
	fclose(f);
	return buf;
}

bool fs_exists(const char *path)
{
	FILE *fptr;
	bool exists;

	fptr = fopen(path, "r");
	if (fptr) {
		exists = true;
	} else {
		exists = false;
	}

	return exists;
}

int fs_append(const char *path, const char *format, ...)
{
	FILE *fptr;
	va_list args;
	va_start(args, format);

	if (vfprintf(fptr, format, args) < 0) {
		va_end(args);
		fclose(fptr);
		return -1;
	}

	va_end(args);

	fptr = fopen(path, "a");

	return 0;
}

int fs_del(const char *path)
{
	if (!remove(path)) {
		return -1;
	}
	return 0;
}

int fs_new(const char *path)
{
	size_t len;
	int fd;

	if (path == NULL) {
		errno = EINVAL;
		return -1;
	}

	len = strlen(path);
	if (len == 0) {
		errno = EINVAL;
		return -1;
	}

	if (path[len - 1] == '/') {
		if (mkdir(path, 0777) == -1)
			return -1;
	} else {
		fd = open(path, O_CREAT | O_EXCL | O_WRONLY, 0666);
		if (fd == -1)
			return -1;
		close(fd);
	}

	return 0;
}

int fs_write(const char *path, const char *format, ...)
{
	FILE *fptr;
	va_list args;
	va_start(args, format);

	fptr = fopen(path, "w");
	if (!fptr) {
		return errno;
	}

	if (vfprintf(fptr, format, args) < 0) {
		va_end(args);
		fclose(fptr);
		return -1;
	}
	va_end(args);

	return 0;
}

FILE *fs_temp()
{
	FILE *fptr = tmpfile();

	if (!fptr) {
		perror("tmpfile failed");
		return NULL;
	}

	return fptr;
}
