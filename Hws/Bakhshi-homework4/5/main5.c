// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{

	int n;										/* Aval Baze */
	int m;										/* Akhar Baze */

	int c, b, a;									/* Azlae Mosallas */
	scanf("%d %d", &n, &m);

	for (c = n; c <= m; c++)
	{
		for (b = n; b <= m; b++)
		{
			for (a = n; a <= m; a++) {
				if (c*c == b*b + a*a) {
					printf("%d %d %d\n", c, b, a);
				}
			}
		}

	}
	return 0;
}
