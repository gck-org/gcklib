/*
 *   gcklib.fs - Contains file system related iterations
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

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "err.h"

#include "fs.h"

char *fs_read(const char *path)
{
	FILE *fptr = fopen(path, "r");
	if (!fptr)
		return NULL;

	size_t cap = 1024;
	size_t len = 0;
	char *buf = malloc(cap);
	if (!buf) {
		fclose(fptr);
		return NULL;
	}

	int c;
	while ((c = fgetc(fptr)) != EOF) {
		if (len + 1 >= cap) {
			cap *= 2;
			char *tmp = realloc(buf, cap);
			if (!tmp) {
				free(buf);
				fclose(fptr);
				return NULL;
			}
			buf = tmp;
		}
		buf[len++] = (char)c;
	}
	buf[len] = '\0';

	fclose(fptr);
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
	FILE *fp = fopen(path, "a");
	if (!fp)
		return -1;

	va_list ap;
	va_start(ap, format);
	int ret = vfprintf(fp, format, ap);
	va_end(ap);

	if (ret < 0) {
		fclose(fp);
		return -1;
	}

	if (fclose(fp) != 0)
		return -1;

	return ret;
}

int fs_del(const char *path)
{
	return remove(path);
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
	FILE *fptr = fopen(path, "w");
	if (!fptr)
		return -1;

	va_list ap;
	va_start(ap, format);
	int ret = vfprintf(fptr, format, ap);
	va_end(ap);

	if (ret < 0) {
		fclose(fptr);
		return -1;
	}

	if (fclose(fptr) != 0)
		return -1;

	return ret;
}

FILE *fs_temp()
{
	FILE *fptr = tmpfile();

	if (!fptr) {
		errorf("tmpfile failed");
		return NULL;
	}

	return fptr;
}

/* end of file fs.c */
