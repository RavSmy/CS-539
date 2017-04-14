/*
	Ravela Smyth 
	LAB 5B - String Cleaner

	4/18/2017
	CS 539 
*/


#include<stdio.h>
#include<stdlib.h>

/*DECLARE*/


void generate(char *ptr_s1, char *tracker);

void get_user(char *ptr_s2, char *c, int *error, char *tracker);

void string_machine(char *ptr_s1, char *ptr_s2, char c, char *ptr_out, char *tracker1, char *tracker2);
int search(char a, char *string);

/*MAIN*/

int main(void) {
	char s1[41] = { '\0' }, s2[100] = { '\0' }, str_out[41] = { '\0' }, c = '\0', again[100], *tracker = &s2, *tracker2 = &s2;
	int error;

    puts("---------String Cleaner: LAB 5---------");

	/*Generate S1*/ 
    generate(&s1, *tracker);

    do{
       
	    error = 0;

    	/*Get S2 and Replacement Character*/
    	get_user(&s2, &c, &error, *tracker); 

        /*Replace S1*/
	    string_machine(&s1, &s2, c, &str_out, *tracker, *tracker2);

        /*Output*/
        puts("");	
	    puts(s1);
	    puts(s2);
	    puts(str_out);
		puts("");	

        /*Again?*/ 
		printf("Again?--   "); 
		fgets(again, 100, stdin);
	    puts("---------------------------------------");
	
	} while (again[0] == 'Y' || again[0] == 'y'); 

}


/*FUNCTIONS*/

/*To generate S1*/
void generate(char *ptr_s1, char *tracker) {
	tracker = ptr_s1;
	for (int i = 0; i < 40; i++) {
		*(tracker++) = rand() % 26 + 'A';
	}
	*tracker = '\0';
}

void get_user(char *ptr_s2, char *c, int *error, char *tracker) {
	int i;

	/*Getting S2*/
	do {
		printf("\nInput Your String--   ");
		fgets(ptr_s2, 100, stdin);

		tracker = ptr_s2;
		*error = 0;

		for (i = 0; (*tracker) != '\0'; i++) {
			/*If not Uppercase Letter, error*/
			if ((*tracker < 'A' || *tracker > 'Z') && *tracker != '\n') {
				*error = 1; break;
			}
			tracker++;
		}

		if (i < 4 || i > 21) { *error = 1; }


		if (*error == 1)
			printf("                   Try Again!");

	} while (*error == 1);

    /*Set last char in S2 to null*/
    *(tracker-1) = '\0';

	/*Gettiing Character*/
	do {
		printf("Input Your Character--   ");
		*c = getchar(); 
        *error = 0; 

		/*If the next char is not \n, error*/
		while (getchar() != '\n') { *error = 1; }

		if (*error == 1)
			printf("                   Try Again!\n");

	} while (*error == 1);
}


void string_machine(char *ptr_s1, char *ptr_s2, char c, char *ptr_out, char *tracker1, char *tracker2) {

	tracker1 = ptr_s1;

	for (int i = 0; i < 40; i++) {
		tracker2 = ptr_s2;
        /*If Chars match, replace with c*/
		if (search(*tracker1, tracker2)) 
			*ptr_out = c;
		/*Else copy current char*/
		else
			*ptr_out = *tracker1;

		*(tracker1++);
		*(ptr_out++);
	}

	*tracker1 = '\0';
}

int search(char a, char *string) { 

	while (*string != '\0') {
		/*If chars match, found*/
		if (*string == a)
			return 1;
		*(string++);
	}

	return 0;
}
