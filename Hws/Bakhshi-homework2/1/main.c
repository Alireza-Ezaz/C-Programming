#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
	int i, j; 
	double d;
	float f;
	i = d = j = f = 10;
	printf("%f\n",j);
	i = d * j + 1.0;
	printf("%d\n", j);
	j = (int)i % (int)((double)f * j);
	printf("%d, %d\n", i, j);


	return 0;
}