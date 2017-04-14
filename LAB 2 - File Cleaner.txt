/* Ravela Smyth */
/* SECTION 3118 [CS 539] */
/* LAB 2 */
/* This program outputs a cleaned paragraph */

#include <stdio.h>

main() {

	char c = '\0';
	int j = 0;
	FILE *poem, *output;

	poem = fopen("poem.txt", "r+");
	output = fopen("output.txt", "w+");
	
	for (int i = 0; c != EOF; i++) {

		c = getc(poem);

		if (isdigit(c) || isalpha(c)) {
			fputc(c, output); j = 1;
		}
		else if (j == 1) {
			fputc('\n', output); j++;
		}

	} 

	fclose(poem); fclose(output);
}

