// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int n;				//Adad
	int counter = 0;
	int i = 0;
	int j;
	int k;
	int x[10];			//Zakhire Argham
	scanf("%d", &n);

	while (n != 0)
	{
		counter += 1;
		x[i] = n % 10;
		n = n / 10;
		i++;
	}

	for (j = 1; j <= counter; counter--)
	{
		for (k = 1 , printf("%d: ", x[counter - 1]); k <= x[counter - 1]; k++)
			printf("%d", x[counter - 1]);

		printf("\n");
		
	}






	return 0;
}