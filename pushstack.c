/*
Filename: pushstack.c
Author: Daniel Sauder
Website: http://govolution.wordpress.com/
License: http://creativecommons.org/licenses/by-sa/3.0/

- generate asm code that pushes a given string on the stack in reverse order
- fill up with empty spaces if neccessary
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argv[1]==NULL)
	{
		printf("usage: pushstack \"foo bar\"\n");
		return 0;
	}

	char *buf=argv[1];
	int l=strlen(buf);
	int x;

	// fill with spaces if neccessary
	int ll=4-(l%4);
	if (ll!=4)
	{
		printf("push 0x");
		for (x=0;x<ll;x++)
			printf("20");
	}
	
	// printf asm code to screen
	for (x=l; x>0; x--)
	{
		if ((x%4)==0) printf("push 0x");
		printf("%02X",buf[x-1]);
		if ((x%4)==1) printf("\n");
		
	}
	printf("\n");
	return 0;
}
