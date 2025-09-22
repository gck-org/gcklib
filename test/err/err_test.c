#include <stdbool.h>
#include "../../lib/err.h"

int main(int argc, char **argv)
{
	error(-1);

	errorf("errorf: %s", "success");
	notef("notef: %s", "success");
	warnf("warnf: %s", "success");

	errorfc("errorfc: %s", "success");
	notefc("notefc: %s", "success");
	warnfc("warnfc: %s", "success");

	if (argc < 2) {
		fatalf("not enough arguments: got %d", argc);
	} else {
		fatalfc("too many arguments: got %d", argc);
	}
}
