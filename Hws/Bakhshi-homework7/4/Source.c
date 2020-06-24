// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int x;
	int y;
}point;

struct node {
	point data;
	struct node *next;
};


/*making a linked list*/
void makelist(struct node *cell)
{
	static int count = 1;
	scanf("%d %d", &(cell->data.x), &(cell->data.y));
	if (count == 10)
		cell->next = NULL;
	else
	{
		count++;
		cell->next = (struct node *)malloc(sizeof(struct node));
		makelist(cell->next);
	}


}


/*this function remove nodes from cells*/
void remove_node(struct node **cell, struct node *target) {
	if (*cell == target) {
		*cell = target->next;
		free(target);
		return;
	}
	struct node *current = *cell;
	while (current->next != target) {
		current = current->next;
	}
	current->next = target->next;
	free(target);
}


void checklist(struct node *cell)
{
	struct node *current = cell;
	struct node *current2 = cell;
	point temp;

	while (current2->next != NULL)
	{
		temp = current2->data;
		while (current->next != NULL)
		{
			if (temp.x == current->data.x)
				if (current->data.y > temp.y)
				{
					struct node *current1 = current->next;
					remove_node(&cell, current);
					current = current1;
					continue;
				}
			current = current->next;

		}
		current = cell;
		current2 = current2->next;
	}




}


/*printing the list*/
void displaylist(struct node *cell)
{
	printf("%d %d\n", cell->data.x, cell->data.y);
	if (cell->next != NULL)
		displaylist(cell->next);

}
//////////////////////////////////////////////////////////////////////////



int main(void)
{
	struct node *start;
	start = (struct node *)malloc(sizeof(struct node));
	makelist(start);
	checklist(start);
	checklist(start);
	displaylist(start);





	return 0;
}
