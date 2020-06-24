#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) 
{
	int n , m , random_number;
	int result;
	int i = 0;
	scanf("%d %d", &n, &m);
	

	while (i < 4)
	{

		random_number = rand();
		result = (random_number % (n - m)) + m;
		if (result % 2 == 0) 
		{
		printf("%d ", result);
		i++;
		}
		else
		{
			random_number = rand();
			result = (random_number % (n - m)) + m;
		}
	}
	
	return 0;
}