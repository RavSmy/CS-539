#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>

void create_data(user_data *users[]) 
{
	char new_user[100]; 
	int i = 0; 
	user_data *temp;
	
	while (gets(new_user) != NULL && i < 50) 
	{
		
		temp = (user_data*)malloc(sizeof(user_data));

		strcpy(temp->name, new_user);
		gets(temp->address);
		gets(temp->city);
		gets(temp->zipcode);

		users[i++] = temp; 
	};
		
	users[i] = NULL;
}

void sort_data(user_data *users[]) 
{
	user_data *temp; 

	for (int i = 0; users[i] != NULL; i++) 
		for (int j = i+1; users[j] != NULL; j++)
			if (strcmp(users[i]->zipcode, users[j]->zipcode) > 0) 
			{
				temp = users[j];
				users[j] = users[i];
				users[i] = temp;
			}
}

void print_data(user_data *users[]) 
{
	for (int i = 0; users[i] != NULL; i++)
		printf("%s\n%s\n%s\n%s\n", users[i]->name, users[i]->address, users[i]->city, users[i]->zipcode);
}

void free_mem(user_data *users[]) 
{
	for (int i = 0; users[i] != NULL; i++) 
		free((void*)users[i]);
}