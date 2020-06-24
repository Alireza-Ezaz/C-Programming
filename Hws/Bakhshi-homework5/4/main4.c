// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int seri[1000] = {1 ,1 ,1 };
	int i,j,k;
	for (i = 3; i < 1000; i++)
		seri[i] = seri[i - 3] + seri[i - 2] - 2 * seri[i - 1];
	int m;
	scanf("%d", &m);

	for (j = 0; j < 1000; j++)
	{
		for (k = 0; k < 1000; k++)
		{
			if (m - seri[j] == seri[k])
			{
				if(seri[j] <= seri[k])
				printf("%d %d\n", seri[j], seri[k]);
				else
				printf("%d %d\n", seri[k], seri[j]);

				break;
			}
		}
		if (m - seri[j] == seri[k])
			break;
	}
	


	return 0;
}