#include <stdio.h>
#define PI 3.14
#include <math.h>

int main(void)
{
	double ab;
	double a_b_c;
	double bc;
	double b_c_d;
	double h, cd, r1, r2;
	double primeter, area;
	
	scanf("%lf%lf%lf%lf", &ab, &a_b_c, &bc, &b_c_d);


	a_b_c = (2 * PI * a_b_c) / 360.0;
	b_c_d = (2 * PI * b_c_d) / 360.0;

	a_b_c = a_b_c - PI / 2.0;
	b_c_d = b_c_d - PI / 2.0;

	h = ab * cos(a_b_c);
	r1 = ab * sin(a_b_c);
	cd = h / cos(b_c_d);
	r2 = cd * sin(b_c_d);
	

	primeter = 2 * bc + ab + r1 + r2 + cd;
	area = (2 * bc + r1 + r2) * h / 2;
	
	printf("Perimeter: %.2lf\nArea: %.2lf\n",primeter,area);











	return 0;
}