/*
	"Main.c"
	Ravela Smyth
	LAB 6B, 7B
	CS 539
	5/9/2017
*/

#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	user_data *all_users[51];
	
	create_data(all_users);
	sort_data(all_users);
	print_data(all_users);
	free_mem(all_users);

}

