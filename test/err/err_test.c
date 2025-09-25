#include <stdbool.h>
#include "../../lib/err.h"

int main(int argc, char **argv)
{
	err_init;

	errorfa(0);
	warnfa(0);
	notefa(0);
	hintfa(0);

	fatalf("all err tests passed");

	return 0;
}
