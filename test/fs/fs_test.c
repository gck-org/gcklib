#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../lib/fs.h"

static void test_new_and_exists(void)
{
	const char *path = "testfile.txt";
	if (fs_exists(path))
		fs_del(path);

	if (fs_new(path) != 0) {
		fprintf(stderr, "fs_new failed\n");
		exit(1);
	}

	if (!fs_exists(path)) {
		fprintf(stderr, "fs_exists failed after fs_new\n");
		exit(1);
	}
}

static void test_write_and_read(void)
{
	const char *path = "testfile.txt";
	const char *msg = "hello world\n";

	if (fs_write(path, "%s", msg) < 0) {
		fprintf(stderr, "fs_write failed\n");
		exit(1);
	}

	char *content = fs_read(path);
	if (!content || strcmp(content, msg) != 0) {
		fprintf(stderr, "fs_read mismatch\n");
		free(content);
		exit(1);
	}
	free(content);
}

static void test_append(void)
{
	const char *path = "testfile.txt";
	const char *msg = "extra\n";

	if (fs_append(path, "%s", msg) < 0) {
		fprintf(stderr, "fs_append failed\n");
		exit(1);
	}

	char *content = fs_read(path);
	if (!content || strstr(content, msg) == NULL) {
		fprintf(stderr, "fs_append not found in file\n");
		free(content);
		exit(1);
	}
	free(content);
}

static void test_temp(void)
{
	FILE *tmp = fs_temp();
	if (!tmp) {
		fprintf(stderr, "fs_temp failed\n");
		exit(1);
	}
	fprintf(tmp, "tempdata\n");
	fclose(tmp);
}

static void test_del(void)
{
	const char *path = "testfile.txt";
	if (fs_del(path) != 0) {
		fprintf(stderr, "fs_del failed\n");
		exit(1);
	}
	if (fs_exists(path)) {
		fprintf(stderr, "file still exists after fs_del\n");
		exit(1);
	}
}

int main()
{
	test_new_and_exists();
	test_write_and_read();
	test_append();
	test_temp();
	test_del();
	printf("all fs tests passed\n");
	return 0;
}
