// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
//homework3-tamrin4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c ;						//andaze azlae mosallas
	
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	
	if ((a + b <= c) || (b + c <= a) || (c + a <= b))
		printf("0\n");
			else if( (a==b) || (b==c) || (c==a) )
					 if ( (int)(pow(a, 2.0) + pow(b, 2.0) == (int)pow(c, 2.0)) || (int)(pow(c, 2.0) + pow(b, 2.0) == (int)pow(a, 2.0)) || (int)(pow(a,2.0) + pow(c,2.0) == (int) pow(b,2.0)) )
					 printf("2\n");
					 else
					 printf("1\n");
				else 
				printf("4\n");


	





	return 0;
}