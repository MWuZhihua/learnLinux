#include <stdio.h>
#include "add.h"

int main()
{
	int r1 = add1(2 ,3);

	double r2 = add2(2.1 , 2.2);

	printf("r1 = %d , r2 = %lf\n", r1, r2);

	return 0;
}
