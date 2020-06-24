// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char word[50];
	int cnt;

} information;
int flag = 0;

information result[100];//global struct
						////////////////////////////////////////////////////////////////////////////////////////////////
int frequency(int rows, int len, char strings[][len], information result[100])
{
	int i = 0;
	//printf("%s",strings[1]);
	int j = 0;
	int k = 0;
	int word_counter = 0;
	int z;
	for (z = 0; z < rows; z++)
	{
		while (strings[z][j] != '\0')
		{
			if (strings[z][j] == ' ' || strings[z][j] == '\n')
			{
				result[i].word[k] = '\0';
				k = -1;

				/*moghaeseh ba ghabli haye result*/
				for (int r = 0; r < word_counter; r++)
				{
					if (strcmp(result[i].word, result[r].word) == 0)
					{
						result[i] = result[i + 1];
						result[r].cnt++;
						i--;
						word_counter--;
					}
				}
				i++;
				word_counter++;




			}

			else
			{
				result[i].word[k] = strings[z][j];
				//printf("result[%d].word[%d]%c\n", i, k, result[i].word[k]);
			}

			j++;
			k++;

		}
		j = k = 0;
		i++;
		word_counter++;
		//	for(int i = 0; i < 3; i++)
		//printf("%s",result[i].word);
	}
	//////////////////////////////////////////////////////
	for (int r = 0; r < word_counter - 1; r++)
	{
		if (strcmp(result[word_counter - 1].word, result[r].word) == 0)
		{
			result[word_counter - 1] = result[word_counter];
			result[word_counter - 1].word[0] = 'z';
			result[r].cnt++;
			flag = -1;

		}
	}

	////////////////////////////////////////////////////

	return word_counter;
}
///////////////////////////////////////////////////////////////////////////////
void sort(information result[100], int x)
{
	int i, j;
	char temp[50];
	int temp1;
	for (i = 0; i < x - 1; i++)
		for (j = i + 1; j < x; j++)
			if (strcmp(result[i].word, result[j].word) > 0)
			{
				strcpy(temp, result[i].word);
				strcpy(result[i].word, result[j].word);
				strcpy(result[j].word, temp);
				temp1 = result[i].cnt;
				result[i].cnt = result[j].cnt;
				result[j].cnt = temp1;

			}




}






int main(void)
{

	int len, rows;
	int i;
	scanf("%d%d\n", &rows, &len);
	char strings[rows][len];

	for (int i = 0; i < 100; i++)
		result[i].cnt = 1;



	for (i = 0; i < rows; i++)
	{
		gets(strings[i]);
		//puts(strings[i]);
	}

	int w = frequency(rows, len, strings, result);
	sort(result, w);
	printf("%d\n", w + flag);

	for (int i = 0; i < w + flag; i++)
		printf("%s %d\n", result[i].word, result[i].cnt);

	//for (int i = 0; i < w; i++)
	//printf("%d ", result[i].cnt);







	return 0;
}
