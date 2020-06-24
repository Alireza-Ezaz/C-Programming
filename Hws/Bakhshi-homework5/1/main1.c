// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d %d %d", &a1, &b1, &c1);
	scanf("%d %d %d", &a2, &b2, &c2);

	double x1, x2;

	if (a2 * b1 == a1 * b2)
		printf("No Solution\n");
	else
	{
		x2 = (c1 * a2 - c2 * a1) / (double)(a2 * b1 - a1 * b2);
		x1 = (c1 * b2 - c2 * b1) / (double)(a1 * b2 - a2 * b1);

		printf("%.2lf %.2lf\n",x1, x2);

	}

	






	return 0;
}