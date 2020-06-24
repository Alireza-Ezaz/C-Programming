// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int main(void)
{
	int n;			//Tedad Adad ha
	int digits;		//Tedad ragham ha
	int i, j, k;
	int correct_cnt = 0, incorrect_cnt = 0;
	float score;
	int end = 0;

	long int r[20];
	time_t t = time(NULL);

	scanf("%d %d", &n, &digits);
	while (end == 0)
	{

		for (k = 1; k <= 5; k++)
		{

			for (i = 1; i <= n; i++)
			{
				srand(t*i*k);
				r[i - 1] = (rand() % ((int)pow(10, digits) - (int)pow(10, digits - 1))) + pow(10, digits - 1);
				printf("%d ", r[i - 1]);
				if (i == n)
					printf("\n");
			}

			getchar();

			//system("cls");

			for (j = 1; j < i; j++)
			{
				int temp;
				scanf("%d", &temp);


				if (temp == r[j - 1])
				{
					correct_cnt = correct_cnt + 1;
					printf("Correct :) :D\n");

				}
				else
				{
					printf("Incorrect :( :P\n");
					incorrect_cnt += 1;
				}

			}
			score = correct_cnt / ((float)(n)* k);
			printf("%.2f\n", score);

			score = 0;
			//	correct_cnt = 0;
			//	incorrect_cnt = 0;

		}
		printf("1)Continue\n2)Increase numbers\n3)Increase digits\n4)End\n");
		int z;
		scanf("%d", &z);
		switch (z)
		{
		case 2:
			n += 1;
			break;
		case 3:
			digits++;
			break;
		case 4:
			end = 1;
			break;
		}

	}




	return 0;
}
