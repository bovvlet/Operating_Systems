#include <stdio.h>
#include <stdlib.h>

int main()
{
	for( int i=0;i<10;i++)
	{
        	void* x = malloc(1e7);
        	memset(x, 0, sizeof(x));
        	sleep(1);
    	}
}
// background task 2, "vmstat 1" -> si and so fields remain 0
// background task 3,      "top" -> shows that it's usage of memory increases

