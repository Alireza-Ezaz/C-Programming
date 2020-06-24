// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
//homework 3 - Tamrin 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


int main(void)
{
	bool p, q,z;

	int r, s;

	p = false;
	q = (0 == 0); 
	r = 0; 
	s = 100;

	z = (p == q) == (q <= !r);

	printf("The answer is %d \n", z);


	return 0;
}