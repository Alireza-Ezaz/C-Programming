// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double a, b, c;

bool check_1(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double a, b, c;
	a = (x1 - x2) * (x1 - x2 )+ (y1 - y2) * (y1 - y2);
	b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
	c = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
	if (  ((sqrt(a) + sqrt(b) > sqrt(c)) && (sqrt(b) + sqrt(c) >sqrt(a)) && (sqrt(c) + sqrt(a) >sqrt(b))) && (      a + c == b  ||
															    b + c == a  ||
															    a + b == c ) 
		
		)
		return true;
	else
		return false;
}

bool check_2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (check_1(x2, y2, x1, y1, x3, y3) == true && check_1(x3, y3, x2, y2, x4, y4) == true && check_1(x4, y4, x3, y3, x1, y1) == true && check_1(x1, y1, x4, y4, x2, y2) == true)
		return true;
	else
		return false;
}


int main(void)
{
	bool result;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	result = check_2(x1, y1, x2, y2, x3, y3, x4, y4);
	if (result == true)
		printf("True\n");
	else
		printf("False\n");
	
	
	return 0;
}