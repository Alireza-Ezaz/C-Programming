
#include <stdio.h>
int main()
{
	int weight,cost;
	
	scanf("%d", &weight);
	if (weight < 100)
		cost = 1000;
	else if (weight >= 100 && weight < 200)
		cost = 1500;
	else if (weight >= 200 && weight < 300)
		cost = 2000;
	else if (weight >= 300 && weight < 500)
		cost = 3000;
	else
		cost = ((weight - 500) / 100) * 500 + 3000;
	printf("Cost = %d\n", cost);


	return 0;
}


