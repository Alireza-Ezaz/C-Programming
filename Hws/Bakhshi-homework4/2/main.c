// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int n;		//Adad asli
	int m;		//Tedad ragham chap n
	int a;		//ragham khas
	int i = 0;
	int j;
	int k = 0;
	int counter = 0;

	scanf("%d %d %d", &n, &m, &a);

	int x[10];	//Baraye Zakhire kardan Ragham ha

	while (n != 0)
	{
		counter += 1;
		x[i] = n % 10;
		n = n / 10;
		i++;
	}

	for (j = 1; j <= m; j++)
	{
		if (x[counter - 1] == a)
			printf("True");
		else
			k++;

		counter--;
	}
	if (k == m)
		printf("False");
	return 0;
}