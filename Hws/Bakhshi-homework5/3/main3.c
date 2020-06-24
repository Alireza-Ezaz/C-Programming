// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int fib[20] = { 1,1 };
	int i;
	int n;
	scanf("%d", &n);

	for (i = 2; i <= 20; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("%d\n", fib[n]);
	return 0;
}

