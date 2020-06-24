// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi
//Final Project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*global varibals used in the code*/
int file_counter = 0;
FILE *file_pointer_to_choices;




struct node *start;
struct node *start1;

int status = 0;//   0:middle of the game      1:lost
int j = 0;//number of rounds played
char name[100];

int people = 50;
int court = 50;
int Treasury = 50;
int number;	/*number = number of nodes*/

int backup;







/*Essintials for creating linked list-node parameters*/
struct node {
	char problem[200];
	char first_decision[200];
	int people_influence1;
	int court_influence1;
	int treasury_influence1;

	char secound_decision[200];
	int people_influence2;
	int court_influence2;
	int treasury_influence2;

	int possibility;

	int order;

	struct node *next;

};
/* (1) This functoin create a linked list from the files in choices */
int create_list(struct node *new_node) {

	static int number_of_nodes = 1;
	//printf("number of node in create list is %d \n", number_of_nodes);
	char file_name[100];

	fscanf(file_pointer_to_choices, "%s\n", file_name);
	//used for debugging
	//printf("%s\n", file_name);

	file_counter++;

	FILE *file_pointer_to_text;
	file_pointer_to_text = fopen(file_name, "r");

		if (file_pointer_to_text == NULL)
		{
			printf("Can't open C[%d].txt\n",file_counter);
			exit(-1);
		}

		fgets(new_node->problem, 200, file_pointer_to_text);

		fgets(new_node->first_decision, 200, file_pointer_to_text);
		//printf("%s\n",new_node->first_decision);

		fscanf(file_pointer_to_text, "%d", &(new_node->people_influence1));
		//printf("%d\n", new_node->people_influence1);

		fscanf(file_pointer_to_text, "%d", &(new_node->court_influence1));
		//printf("%d\n", new_node->court_influence1);

		fscanf(file_pointer_to_text, "%d\n", &(new_node->treasury_influence1));
		//printf("%d\n", new_node->treasury_influence1);


		fgets(new_node->secound_decision, 200, file_pointer_to_text);
		//printf("%s\n", new_node->secound_decision);

		fscanf(file_pointer_to_text, "%d", &(new_node->people_influence2));
		//printf("%d\n", new_node->people_influence2);

		fscanf(file_pointer_to_text, "%d",&( new_node->court_influence2));
		//printf("%d\n", new_node->court_influence2);

		fscanf(file_pointer_to_text, "%d", &(new_node->treasury_influence2));
		//printf("%d\n", new_node->treasury_influence2);

		new_node->possibility = 3;

		fclose(file_pointer_to_text);

		if (feof(file_pointer_to_choices) != 0)
			new_node->next = NULL;
		else
		{
			number_of_nodes++;
			new_node->next = (struct node *)malloc(sizeof(struct node));
			create_list(new_node->next);
		}
		//printf("function used %d times\n", i);

			return number_of_nodes ;
}




/* (2) This functions check weather the score is more than 100 or not*/
void check_scores(void)
{
	if (people > 100)
		people = 100;
	if (people < 0)
		people = 0;

	if (court > 100)
		court = 100;
	if (court < 0)
		court = 0;

	if (Treasury > 100)
		Treasury = 100;
	if (Treasury < 0)
		Treasury = 0;

}









/* (3) Tihs function say welcome to the user and asks his name and shows the menu*/
void welcome(void)
{
	printf("Hello my friend.\nPlease enter your name\n");
	gets(name);
	printf("Welcome %s What do you want to do??\n\n", name);
	printf("1)New Game\n\n2)Load Game\n\n");
	scanf("%d", &status);
	if (status == 1)
		printf("You have control of a great empire.start your management.\n");
}

/* (4) This function display the current status of gamer*/
void display_result(void)
{
	printf("People : (%d)   ", people);
	printf("Court : (%d)   ", court);
	printf("Treasury : (%d)  \n", Treasury);

}


/* (5) This functoin create a random number between 1 & x(number of nodes) */
int create_randnum(int x)
{
	time_t t = time(NULL);
	srand(t * people * court *Treasury);
	int r = rand();
	r = (r % (x));
	return r;
}
/*(6)This function select a random node from linked list and decrease the possiblity of it(x is a rand num )*/
struct node select_randnode(struct node *list)
{
	int x = create_randnum(number);
	//printf("rand is :%d\n",x);
	struct node *current = list;
	for (int i = 0; i < x; i++)
	{
		current = current->next;
	}
	(current->possibility)--;
	return *current;
}




struct saved_data {
	char saved_name[100];
	int saved_status;
	int saved_possiblities[100];//100 is numbers of txt files we have
	int saved_people;
	int saved_court;
	int saved_treasury;
};



/* (7) This function collect the information needed for saving in a struct */
struct saved_data save(struct node *x, int y)
{
	struct node *current = x;
	struct saved_data s;
	strcpy(s.saved_name, name);
	s.saved_status = status;
	//first of all;we set 0 for frequency of each possiblity
	for (int i = 0; i < y; i++)
		s.saved_possiblities[i] = 0;

	while (current != NULL)
	{
		int temp = current->order;
		s.saved_possiblities[temp] = current->possibility;

		current = current->next;


	}
	s.saved_people = people;
	s.saved_court = court;
	s.saved_treasury = Treasury;


	return s;
}




/* (8) this function runs the game: 1-showing the problem & decisions 2-the gamer choose the decision 3- parameters chenge 4-displaying list*/
void run_game(struct node x)
{
	int temp;
	printf("%s\n", x.problem);
	printf("1)%s\n", x.first_decision);
	printf("2)%s\n", x.secound_decision);
	printf("-1)Exit\n");
	scanf("%d", &temp);

	if (temp == 1)/*first decision selected*/
	{
		people = people + x.people_influence1;
		court = court + x.court_influence1;
		Treasury =Treasury + x.treasury_influence1;
		//display_result();
	}

	if (temp == 2)/*first decision selected*/
	{
		people = people + x.people_influence2;
		court = court + x.court_influence2;
		Treasury = Treasury + x.treasury_influence2;
		//display_result();
	}
	if (temp == -1)/*Exit*/
	{
		printf("Do you want to save your game??(Yes = 1 & No = 0)\n");
		int temp;
		scanf("%d", &temp);
		if (temp == 0)
			exit(-1);

		if (temp == 1)
		{
		struct saved_data b = save(start, backup);
		for(int i=0 ;i<7;i++)
		printf("%d\n", b.saved_possiblities[i]);



		}


	}

	if (temp != 1 && temp != 2 && temp != -1)
	{
		printf("Wrong input,Enter a valid number\nYour previous choice did not have any influence on empire\n");
		/////////////////////////////
		return(-1);
	}

}


/* (9) This functions check weather the game is finished or not*/
int check_result(void)
{
	float average;
	int flag = 0;
	average = (float)(people + Treasury + court) / 3;

	if(average <= 10)
	{
		printf("You lost the game because of dissatisfiction of people,court & treasury\n ");
		flag = 1;
	}
	if (people <= 0)
	{
		printf("You lost the game because of dissatisfiction of people\n ");
		flag = 1;
	}
	if (court <= 0)
	{
		printf("You lost the game because of dissatisfiction of court\n ");
		flag = 1;
	}
	if (Treasury <= 0)
	{
		printf("You lost the game because of dissatisfiction of treasury\n ");
		flag = 1;
	}
	return flag;


}



/* (10) This function remove the nodes with possiblity of 0 */
void delete_node(struct node **list, struct node *target)
{
	/*first node deleting*/
	if (*list == target)
	{
		start = target->next;
		free(target);


	}
	/*other nodes deleting*/
	else
	{
		struct node *current = *list;
		while (current->next != target)
			current = current->next;
		current->next = target->next;
		free(target);

	}

}





/*(11)This function check wheather a node should be deleted or not*/
void check_nodes(struct node *list)
{
	struct node *temp;
	struct node *current =list;
	while (current != NULL)
	{
		if (current->possibility == 0)
		{
			temp = current->next;
			delete_node(&list, current);
			number--;
			//printf("A node was deleted successfully///////////////////////////////////////////////////////////\n");
			current = temp;
			printf("A node deleted sucessfully\n");
			continue;
		}
		//printf("hellooooooooooooooooooooooooo\n");
		current = current->next;
	}

}
/* (12) This function gives each node an index*//*used for saving*/
void give_ordedr_to_nodes(struct node *x)
{
	int i = 0;
	struct node *current = x;
	while (current != NULL)
	{
		current->order = i;
		i++;
		current = current->next;

	}

}










/* (13) This function loads the game */












int main(void)
{

	start = (struct node *)malloc(sizeof(struct node));
	file_pointer_to_choices = fopen("CHOICES.txt", "r");
		if (file_pointer_to_choices == NULL)
			{
				printf("Can't open CHOICES.txt\n");
				exit(-1);
			}

	 welcome();

	/*number = number of nodes*/
	number = create_list(start);
	/*take backup of number*/
	backup = number;

	give_ordedr_to_nodes(start);

	//printf("number is %d\n", number);
	fclose(file_pointer_to_choices);

	/*the game starts here*/
	while (1)
	{
		//printf("It's me\n");
		//printf("start is %d\n", start);
		struct node randnode = select_randnode(start);//we shoud pass randnode to a function which runs the game

		run_game(randnode);

		check_scores();

		display_result();

		check_nodes(start);

		if (number == 0)//if all nodes were deleted this command will create a new list
		{
			start = (struct node *)malloc(sizeof(struct node));
			printf("Nice job %s.You have played well till now.Go on.\n", name);

			file_pointer_to_choices = fopen("CHOICES.txt", "r");
			if (file_pointer_to_choices == NULL)
			{
				printf("Can't open CHOICES.txt\n");
				exit(-1);
			}

			j++;
			number = create_list(start) -(backup * j);// -7(backup) is due to the number of nodes in create list which is a static varibles and we cant't chenge it

			give_ordedr_to_nodes(start);

			printf("number is %d\n", number);
			fclose(file_pointer_to_choices);
			continue;

		}

		int check = check_result();
		if (check == 1)
		{
			status = 1;
			return -1;
			//when you lose the game...
		}
	}










	return 0;
}
