/* Ravela Smyth */
/* SECTION 3118 [CS 539] */
/* LAB 1 */
/* This program calculates a triangle (area, type, etc) */


#include <stdio.h>
#include <math.h>


int main() {

	char again;											/* setup for repeat loop prompt */
	int s1, s2, s3;
	float s, area;

	printf("****WHAT IS THE AREA OF YOUR TRIANGLE?****");						/* title */

	do {

		    

			printf("\n\nPlease enter your three sides:\n");					/* prompts and inputs sides from user */

			scanf("%d", &s1);
			scanf("%d", &s2);
			scanf("%d", &s3);


			/* checking for triangleness */

			if (!((s1 + s2) > s3) || !((s2 + s3) > s1) || !((s3 + s1) > s2))		/* if not, output to user and skip to repeat loop prompt */
					printf("\n   THIS IS NOT A TRIANGLE\n\n");



			else {										/* if so...BEGGINING of triangle calculations... */


					printf("\n   %.0d ---- %.0d ---- %.0d\n   TYPE: ", s1, s2, s3);		/* print the sides once more */



					if (s1 == s2 && s2 == s3)					/* checking for type of triangle */
						printf(" EQUILATERAL\n");
					else if (s1 == s2 || s2 == s3 || s1 == s3)
						printf(" ISOSCELES\n");
					else
						printf(" SCALENE\n");



					s = (s1 + s2 + s3) / 2.0;
					area = sqrt(s*(s - s1)*(s - s2)*(s - s3));


					printf("   AREA:  %f \n\n", area);				/* output area */


		}											/* END of triangle calculations. */


			printf("   AGAIN? (Y/N) : ");							/* repeat loop prompt */
			scanf(" %c", &again);

	} while (again == 'Y' || again == 'y');								/* continue if user responded yes */


	printf("\n\n   !!THANK YOU!! :)\n\n ");								/* end of program message */
}