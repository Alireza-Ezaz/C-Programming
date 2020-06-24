
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double a=1.0;
	double b = 1.0;
	double c = 1.0;
	double d = 1.0;

	double result_a, result_b, result_c, result_d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	
		result_a = (a / (a + b)) + (b / (b + c)) + (c / (c + d));

		result_b = exp((log(fabs(a)) / log(10)) + (sin(b)) + tan(c));

		result_c = a * (b + a) * b * log(c);

		result_d = pow(((1 / pow(a, 1.2)) + (2 / pow(b, 2.3))), 4.5);

		printf("a: %.2lf\nb: %.2lf\nc: %.2lf\nd: %.2lf\n", result_a, result_b, result_c, result_d);
	

	return 0;
}


