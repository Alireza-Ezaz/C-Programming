// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
//homework3-tamrin 5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int a1, b1, a2, b2;
	int a, b;
	int counter = 0;

	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

	a = fmax(a1 , a2);
	b = fmin(b1, b2);

	while (counter < (b - a))
	{
		counter += 1;
	}
	printf("%d\n", counter);







	return 0;
}