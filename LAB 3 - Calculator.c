/**
    CS 539
    Ravela Smyth
    Lab 3B

    3/21/2017

*/


#include<stdio.h>
#include<math.h>


/* ========= FUNCTION DECLARATIONS ========== */


int isdigit(int);
int isoperator(int);
int spaces(char);
int remaining(int, int, int, int, char); 
int convert(int, int);

int CALCULATOR(char, int, int, int); 

void prompts(int);


/* ========= MAIN ========== */


int main (void){
    
    /*variables*/
	int x, firstnum, secondnum, again;
	char oper = '\0';
	
    /*flags*/
	int error_found, first_num_found, second_num_found;
    
    prompts(1);
    
    do {
        
        /*reset variables*/ 
        error_found = 0, first_num_found = 0, second_num_found = 0, firstnum = 0, secondnum = 0, oper = '\0';
        
        prompts(2);
	    x = getchar();
	    prompts(2);
        
        
        
        /*Get spaces*/
    	x=spaces(x);
    	
    	/*Find FIRST digit and convert to number*/
	    while (isdigit(x) == 1) {
		    first_num_found = 1;
		    putchar(x);
		    firstnum = convert(firstnum, x);
		    x = getchar();
    	}
        
        /*Get spaces*/
    	x=spaces(x);
        
        /*Get Operator*/
	    if (isoperator(x) == 1) {
		    putchar(x);
		    oper = x;
	    	x = getchar();
	    }
        
        /*Get spaces*/
	    x=spaces(x);


    	/*Find SECOND digit and convert to number*/
    	while (isdigit(x) == 1) {
		    second_num_found = 1;
		    putchar(x);
		    secondnum = convert(secondnum, x);
		    x = getchar();
	    }
	    
	    /*If all worked, then the remaining should only be spaces. If numbers and operand were not found, error. */
	   error_found = remaining(x, error_found, first_num_found, second_num_found, oper); 

        
        /*If there wasnot an error, CALCULATE*/
	    if (error_found != 1) {
		    printf("\n          %d %c %d = ", firstnum, oper, secondnum);

            error_found = CALCULATOR(oper, firstnum, secondnum, error_found);

		    /* If was fully successful, Again? */
	    	if (error_found != 1) {
		    	prompts(3);
		    	again = getchar();

		    	do {
		    		x = getchar();
		    	} while (x != '\n');

		    	prompts(4);
	    	}// Again 
    	}
    	/*If there was an error, prompt and reenter equation*/
    	else {
	    	prompts(0);}
        
        
    }while(error_found == 1 || again == 'y' || again == 'Y' );
    

}


/* ========= FUNCTIONS ========== */

int isdigit(int a) {
	if (a >= '0' && a <= '9')
		return 1;
	return 0;
}

int isoperator(int a) {
	if (a == '+' || a == '/' || a == '-' || a == '*' || a == '%')
		return 1;
	return 0;
}

int convert(int sum, int a) {
	return (sum * 10) + (a - '0');
}

int spaces(char c) {
    int last = c;

    while (last == ' '){
        putchar(last);
        last = getchar(); 
    }

    return last; 
 }
 
 
 int remaining(int x, int error_found, int num1, int num2, char oper){
	while (x != '\n') {
		putchar(x);
		if (x != ' ')
			error_found = 1;
		x = getchar();
	}

    if (num1 == 0 || num2 == 0 || oper == '\0')
		error_found = 1;

    return error_found; 
}

 

int CALCULATOR(char oper, int firstnum, int secondnum, int error_found){ 
		switch (oper) {
		case '+': printf("%d", firstnum + secondnum); break;
		case '-': printf("%d", firstnum - secondnum); break;
		case '*': printf("%d", firstnum*secondnum); break;
		case '/':
			if (secondnum != 0)
				printf("%f", (float)firstnum / (float)secondnum);
			else {
				prompts(-2);
				error_found = 1;
			}
			break;
		case '%':
			if (secondnum != 0)
				printf("%d", firstnum%secondnum);
			else {
				prompts(-1);
				error_found = 1;
			}
			break;
		default: prompts(0);
			error_found = 1;

		}

return error_found; 

}





/* ========= PROMPTS ========== */

void prompts(int a) {
	switch (a) {
	case 1: puts("============  WELCOME TO THIS SIMPLE CALCULATOR ============\n");
		break;
	case 2: printf("Equation: "); break;
	case 3: printf("\n  Again?: "); break;
	case 4: puts("- - - - - - - - - - - - - - \n"); break;
	case 0: puts("\n          ERROR. Try again."); break;
	case -1: puts("\n          CANNOT MOD BY ZERO. Try again."); break;
	case -2: puts("\n          CANNOT DIVIDE BY ZERO. Try again."); break;
	}
}