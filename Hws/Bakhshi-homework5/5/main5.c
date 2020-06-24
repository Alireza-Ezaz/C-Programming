// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int size1, size2 ,max_size;
	if (size1 >= size2)
		max_size = size1;
	else
		max_size = size2;
	int arr1[10];
	int arr2[10];
	int i,j;
	int temp;
	int choice;
	printf("Enter size1 and size2\n");
	scanf("%d %d", &size1, &size2);

	printf("Enter vector 1\n");
	for (i = 0; i < size1; i++)
	{
		scanf("%d", &temp);
		arr1[i] = temp;
	}

	printf("Enter vector 2\n");
	for (j = 0; j < size1; j++)
	{
		scanf("%d", &temp);
		arr2[j] = temp;
	}

	/*i = 0;
	j = 0;*/

	printf("1) Add\n2) Sub\n3) Multiply\n4) Max\n5) Min\n6) Change\n7) Print\n8) Exit\n");
	scanf("%d", &choice);

	switch (choice)
	{
/**/	case 1:
			{
			for (i = 0; i < max_size; i++)
				printf("%d ", arr1[i] + arr2[i]);
			printf("\n");
			break;
			}

/**/	case 2:
			{
			for (i = 0; i < max_size; i++)
				printf("%d ", arr1[i] - arr2[i]);
			printf("\n");
			break;
			}

/**/	case 3:		
			{
			int res = 0;
			for (i = 0; i < max_size; i++) 
				res += arr1[i] * arr2[i];
			printf("%d\n", res);
			break;
			}

		case 4:
			{
			int temp1;
			printf("Choose vector\n");
			scanf("%d", temp1);
			if (temp1 == 1)
				{
				int max = arr1[0];
				max = arr1[0];
				for (i = 0; i < size1; i++)
					if (arr1[i] > max) 
						max = i;
					printf("%d\n", max);
					
				}
			break;
			}







	}




	return 0;
}