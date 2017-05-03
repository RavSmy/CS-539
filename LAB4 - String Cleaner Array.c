/*
	Ravela Smyth 
	LAB 4B - String Cleaner

	4/18/2017
	CS 539 
*/

#include <stdio.h>
#include <stdlib.h>

/*DECLARE*/

void generate(char str[]);

void string_machine(char str1[], char str2[], char c, char str_out[]);
int str_search(char str1, char str2[]);

char get_string_char(char str[]);

/*MAIN*/

int main(void) {
	char again[100], str1[41] = { '\0' }, str2[21] = { '\0' }, str_out[41] = { '\0' };

	puts("---------String Cleaner: LAB 4---------");
	
	/*Generate S1*/ 
		generate(str1);

	do {

		/*Get S2 and Replacement Character*/
		char c = get_string_char(str2);

		/*Replace S1*/
		string_machine(str1, str2, c, str_out);

		/*Output*/
		puts("");	
		puts(str1);
		puts(str2);
		puts(str_out);
		puts("");

		/*Again?*/ 
		printf("Again?--   "); 
		fgets(again, 100, stdin);
		puts("---------------------------------------");
	
	} while (again[0] == 'Y' || again[0] == 'y'); 

}

/*FUNCTIONS*/

char get_string_char(char str[]) {
	int i, error, c;

	/*Getting S2*/
	do {
		error = 0; i = 0;
		printf("\nInput Your String--   ");
		while ((str[i] = getchar()) != '\n') {
			/*If not Uppercase Letter, error*/
			if (i == 21 || str[i] < 'A' || str[i] > 'Z' || (str[i] == '\n' && i < 3)) {
				error = 1;
				printf("                 ERROR TRY AGAIN");
				while (getchar() != '\n');
				break;			
			}
			i++;
		}

		if ((i < 3 || i > 20) && error != 1) {
			error = 1; printf("                 ERROR TRY AGAIN");
		}
	} while (error == 1);

	/*Set last char in S2 to null*/
	str[i] = (char)0;

	/*Gettiing Character*/
	do {
		printf("Input Your Character--   ");
		error = 0; 
		c = getchar();
		/*If the next char is not \n, error*/
		if (getchar() != '\n') {
			error = 1;
			printf("                 ERROR TRY AGAIN\n");
			while (getchar() != '\n');
		}
	} while (error == 1);

	return c;
}

/*To generate S1*/
void generate(char str[]) {
	for (int i = 0; i < 40; i++)
		str[i] = rand() % 26 + 'A';
	str[40] = '\0';
}

void string_machine(char str1[], char str2[], char c, char str_out[]) {
	for (int i = 0; i < strlen(str1); i++) {
		/*If Chars match, replace with c*/
		if (str_search(str1[i], str2) != -1)
			str_out[i] = c;
		/*Else copy current char*/
		else {
			str_out[i] = str1[i];
		}
	}
	
}

int str_search(char str1, char str2[]) {
	for (int i = 0; i < strlen(str2); i++) {
		/*If chars match, found*/
		if (str2[i] == str1)
			return i;
	}
	return -1; 
}
