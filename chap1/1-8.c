/*
* exercise 1-8: write a program to count blanks, tabs, and newlines
*
*/

#include <stdio.h>

int main()
{
	int c;
	unsigned int blanks, tabs, nlines;
	
  // these need to be defined separately otherwise junk values are produced
	blanks = 0;
	tabs = 0;
	nlines = 0;	
  
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			blanks++;
		if (c == '\t')
			tabs++;
		if (c == '\n')
			nlines++;		
	}
	printf("blanks: %d\n", blanks);
	printf("tabs: %d\n", tabs);
	printf("new lines: %d\n", nlines);

	return 0;
}
