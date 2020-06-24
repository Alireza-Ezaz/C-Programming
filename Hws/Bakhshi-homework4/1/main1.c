// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <math.h>
//seri a
int is_c(double x)
{
	int i = 0;
	int hasel_zarb = 1;
	int indice = -1;
	double c[15];


	for (i = 0; i < 15; i++)
	{
		hasel_zarb *= i + 1;
		c[i] = pow(hasel_zarb, pow(2, -i));
		//printf("%lf\n" , c[i]);
		if (c[i] - x <= 0.000001 && x - c[i] <= 0.000001)
		{
			indice = i;
		}
	}

	return indice;
}

int is_b(double x)
{
	int i = 0;
	int index = -1;
	double j = 1;
	double b[20];
	for (i = 0; i < 20; i++)
	{
		b[i] = sqrt(10 * j);
		//printf("%lf\n" , b[i]);
		j = j + 1;
		if (b[i] - x <= 0.000001 && x - b[i] <= 0.000001)
		{
			index = i;
		}
	}
	return index;
}
int is_a(double x)
{
	int i = 0;
	double j = 1;
	int index = -1;
	double a[20];
	for (i = 0; i < 20; i++)
	{
		a[i] = 1 / (j);
		//printf("%lf\n" , a[i]);
		j = j + 1;
		if (a[i] == x)
		{
			index = i;
		}
	}
	return index;
}




int main(void)
{
	double x, y;
	int n;
	int res_a[2];
	int res_b[2];
	int res_c[2];
	scanf("%lf%lf%d", &x, &y, &n);
	res_a[0] = is_a(x);
	res_a[1] = is_a(y);
	if (res_a[0] == -1 || res_a[1] == -1)
		printf("Series a: False\n");
	else if (res_a[1] - res_a[0] == n)
		printf("Series a: True\n");
	else printf("Series a: False\n");


	res_b[0] = is_b(x);
	res_b[1] = is_b(y);
	if (res_b[0] == -1 || res_b[1] == -1)
		printf("Series b: False\n");
	else if (res_b[1] - res_b[0] == n)
		printf("Series b: True\n");
	else printf("Series b: False\n");

	res_c[0] = is_c(x);
	res_c[1] = is_c(y);
	if (res_c[0] == -1 || res_c[1] == -1)
		printf("Series c: False\n");
	else if (res_c[1] - res_c[0] == n)
		printf("Series c: True\n");
	else printf("Series c: False\n");

	return 0;

}





