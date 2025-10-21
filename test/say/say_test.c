#include <stdio.h>

#include "../../lib/say.h"

int main(int argc, char **argv)
{
	say("this is an example message");

	alert();

	puts("all say passed");
	return 0;
}
