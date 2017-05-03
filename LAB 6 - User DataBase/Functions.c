/*
	"Functions.c"

	Ravela Smyth
	LAB 6B, 7B
	CS 539
	5/9/2017

*/

#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>

/*Creates up to 50 structures*/
void create_data(user_data *users[]) 
{
	char new_user[100]; 
	int i = 0; 
	user_data *temp;
	
	/*Gets input until no info left*/
	while (gets(new_user) != NULL && i < 50) 
	{
		/*Dynamically Allocates new structure, then copies to array of pointers to structures*/
		temp = (user_data*)malloc(sizeof(user_data));
		
		/*Get info from file*/
		strcpy(temp->name, new_user);
		gets(temp->address);
		gets(temp->city);
		gets(temp->zipcode);

		users[i++] = temp; 
	};
		
	users[i] = NULL;
}

/*Sorts data according the zipcode*/
void sort_data(user_data *users[]) 
{
	user_data *temp; 
	
	/*Sorts smallest number to beginning*/
	for (int i = 0; users[i] != NULL; i++) 
		for (int j = i+1; users[j] != NULL; j++)
			if (strcmp(users[i]->zipcode, users[j]->zipcode) > 0) 
			{
				temp = users[j];
				users[j] = users[i];
				users[i] = temp;
			}
}

/*Outputs data*/
void print_data(user_data *users[]) 
{
	for (int i = 0; users[i] != NULL; i++)
		printf("%s\n%s\n%s\n%s\n", users[i]->name, users[i]->address, users[i]->city, users[i]->zipcode);
}

/*Frees dynamically allocated memory*/
void free_mem(user_data *users[]) 
{
	for (int i = 0; users[i] != NULL; i++) 
		free((void*)users[i]);
}
