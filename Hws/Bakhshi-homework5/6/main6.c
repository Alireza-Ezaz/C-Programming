
// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int money, m50, m10, m5, m2, m1;

	scanf("%d", &money);
	m50 = money / 50;
	money = money - (m50 * 50);
	m10 = money / 10;
	money = money - (m10 * 10);
	m5 = money / 5;
	money = money - (m5 * 5);
	m2 = money / 2;
	money = money - (m2 * 2);
	m1 = money / 1;
	printf("%d\n", m50 + m10 + m5 + m2 + m1);





	return 0;
}


