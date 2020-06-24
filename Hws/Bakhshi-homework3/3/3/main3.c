// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
// homework3-tamrin3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int x1, x2, x3, x4;
	int max1, min1;
	int max2, min2;
	int max, min, mid1, mid2; 
	int temp;	//swap kardan vasat ha

	scanf("%d %d %d %d", &x1, &x2, &x3, &x4);

	//x1 & x2

	if (x1 >= x2)
	{
		max1 = x1;
		min1 = x2;
	}
	else
	{
		max1 = x2;
		min1 = x1;
	}

	//x3 & x4

	if (x3 >= x4)
	{
		max2 = x3;
		min2 = x4;
	}
	else
	{
		max2 = x4;
		min2 = x3;
	}

	//maximum hame adad ha

	if (max1 >= max2)
	{
		max = max1;
		mid1 = max2;
	}
	else
	{
	
		max = max2;
		mid1 = max1;
	}	

	//minimum hame adad ha
	
	if (min1 <= min2)
	{
		min = min1;
		mid2 = min2;
	}
	else
	{
		min = min2;
		mid2 = min1;
	}
	//Adad ha ye vasat
	if (mid1 >= mid2)
	{
		mid1 = mid1;
	}
	else
	{
		temp = mid1;
		mid1 = mid2;
		mid2 = temp;
		
	}

	printf("%d %d %d %d ", max, mid1, mid2, min);












	return 0;
}