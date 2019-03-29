#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "application.h"


void misty_run(char* str, int* len)
{
	int n;
	int l = *len;

	unsigned char buf[32];
	unsigned char key[32];

	for (n = 0; n < *len; n += 16, str += 16, l -= 16)
	{
		/* Set the plain-text */
		memcpy(buf, str, min(16, l));

		misty1_main(buf);
		memcpy(str, buf, 16);
	}


}
