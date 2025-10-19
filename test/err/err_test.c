#include "../../lib/err.h"

int main(int argc, char **argv)
{
	errorfa(0);
	warnfa(0);
	notefa(0);
	hintfa(0);

	gcklib_error(1, -1, "all err tests passed");

	return 0;
}
