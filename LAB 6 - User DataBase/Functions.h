/*
	"Functions.h"
	Ravela Smyth
	LAB 6B, 7B
	CS 539
	5/9/2017
*/

#define FUNCTIONS_H_INCLUDED

typedef struct user_data{
	char name[100];
	char address[100];
	char city[100];
	char zipcode[100];
} user_data; 


void create_data(user_data *users[]);
void sort_data(user_data *users[]);
void print_data(user_data *users[]);
void free_mem(user_data *users[]); 
