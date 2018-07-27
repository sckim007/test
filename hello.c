#include <stdio.h>

#define LOOP_NUMBER 30
int main()
{
	int i = 0;
	for (i=0;i < LOOP_NUMBER;i++)
	{
		print(">>>>>>>>> hello jenkins: %d th, left %d.\n", i, LOOP_NUMBER-1);
	}

	return 0;
}
