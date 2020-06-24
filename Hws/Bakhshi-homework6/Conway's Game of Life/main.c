// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
//Conway's Game of Life

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <Windows.h>

/*court scale*/
const int n;
char **cells;
char **new_cells;



/*function1- faghat avalin bar ejra mishavad*/
void creation_of_court(int n)
{
	int i, j;

	cells = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		cells[i] = (char *)malloc(n * sizeof(char));

	//aval ba space por mikonim bad ba setare
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cells[i][j] = ' ';

	while (true)
	{
		int temp_x, temp_y;
		printf("Enter the position of cells(if you are done enter -1 -1)\n");
		scanf("%d%d", &temp_x, &temp_y);

		if (temp_x == -1 && temp_y == -1)
			break;
		if (temp_x >= n || temp_y >= n)
		{
			printf("Invalid Input.try again\n");
			continue;
		}
		cells[temp_x][temp_y] = '*';
	}
}
/*function2-This function draw the court*/
void draw_court(char **x)
{
	int i, j;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		{
			printf("|%c", x[i][j]);
		}
		printf("|\n");
	}

}
/*functoin3-This function count the neighbour cells*/
int neighbour_cells(int x,int y)
{
	int neighbours = 0;

	if(x - 1 >= 0)
		if (cells[x - 1][y] == '*')
			neighbours++;

	if((x - 1 >= 0) && (y - 1 >= 0))
		if (cells[x - 1][y - 1] == '*')
			neighbours++;

	if((x - 1 >= 0) && (y + 1 <= n - 1))
		if (cells[x - 1][y + 1] == '*')
			neighbours++;

	if(y - 1 >= 0)
		if (cells[x][y - 1] == '*')
			neighbours++;
	if (y + 1 <= n - 1)
		if (cells[x ][y + 1] == '*')
			neighbours++;

	if((x + 1 <= n - 1) && (y + 1 <= n - 1))
		if (cells[x + 1][y + 1] == '*')
			neighbours++;

	if((y - 1 >= 0) && (x + 1 <= n - 1))
		if (cells[x + 1][y - 1] == '*')
			neighbours++;
	if(x + 1 <= n - 1)
	if (cells[x + 1][y] == '*')
		neighbours++;

	return neighbours;
}


/*functoin4-simulate Conway's Game for 1 time*/
void simulate(char **x) 
{
	int i, j;
	new_cells = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		new_cells[i] = (char *)malloc(n * sizeof(char));

	//aval ba space por mikonim bad ba setare
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			new_cells[i][j] = ' ';

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (x[i][j] == '*')
			{
				if (neighbour_cells(i, j) == 1 || neighbour_cells(i, j) == 0 || neighbour_cells(i, j) >= 4)
					new_cells[i][j] = ' ';
				if (neighbour_cells(i, j) == 2 || neighbour_cells(i, j) == 3)
					new_cells[i][j] = '*';
			}
			if (x[i][j] == ' ')
				if (neighbour_cells(i, j) == 3)
					new_cells[i][j] = '*';
		}

}


/*function5-Copy new_cells to cells*/
void copy_arr(char **current,char **new1, int size) 
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			current[i][j] = new1[i][j];
}

/*functoin6-shifting cells down*/

/*functoin7-shifting cells right*/

/*functoin7-Making court ready for next simulation
void new_court(void)
{
	int i, j;
	int flag_down = 0;
	for (i = n - 1, j = 0; j < n; j++)
		if (cells[i][j] == '*')
			flag_down = 1;
	if (flag_down == 1)
	{
		new_cells = (char **)realloc(new_cells, (n + 1) * sizeof(char *));
		new_cells[n] = (char *)malloc(sizeof(char) * 1);
		for (i = 0; i < n; i++)
			new_cells[n - 1 + 1][i] = ' ';
			for (i = 0; i < n + 1; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("|%c", new_cells[i][j]);
				}
				printf("|\n");
			}

	}

	/*int flag_right = 0;
	for (i = 0, j = n - 1; i < n; j++)
		if (cells[i][j] == '*')
			flag_right = 1;
	if (flag_down == 1)
	{
		cells[n] = (char *)realloc(*cells, (n + 1) * sizeof(char));
		for (i = 0; i < n; i++)
			cells[i][n] = ' ';
	}
	for (i = 0; i < n ; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			printf("|%c", cells[i][j]);
		}
		printf("|\n");

	}
}*/



int main(void)
{
	int t ;
	int z = 1;

	printf("Enter the frist scale for n\n");
	scanf("%d", &n);

	printf("Enter the numbers of repitation for t\n");
	scanf("%d", &t);

	creation_of_court(n);

	printf("Before starting\n\n");
	draw_court(cells);


	while (z <= t)
	{
		simulate(cells);
		printf("Step %d\n\n",z);
		draw_court(new_cells);

		printf("\n\n");
	//	new_court();
		copy_arr(cells, new_cells, n);
		z++;
		Sleep(2000);
	}


	return 0;
}