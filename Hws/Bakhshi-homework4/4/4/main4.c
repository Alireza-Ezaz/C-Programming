

// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int is_prime(int x)
{
	//ghesmat 1 (tashkhis aval boodan)

	int i = 1;
	int counter = 0;
	int baghimande;

	while (i*i <= x)
	{
		baghimande = x % i;
		if (baghimande == 0)
		{
			counter = counter + 1;
		}
		i++;
	}

	if (counter == 1 && x != 1)
		return 0;

	else
		return 1;
}

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	printf("2 ");
	for (i = 1; i <= n; i+=2)
	{
	
		if (is_prime(i) == 0)
			printf("%d ", i);
	}





	return 0;
}


