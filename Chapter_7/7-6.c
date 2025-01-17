#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	FILE* fp1;
	FILE* fp2;
	
	//char filename1[] = "test1.txt";
	//char filename2[] = "test2.txt";
	char line1[1000] = " ";
	char line2[1000] = " ";
	int i1 = 0;
	int i2 = 0;
	char f1;
	char f2;

	fp1 = fopen(*++argv, "r");
	fp2 = fopen(*++argv, "r");
	
	// while files are same and EOF has not been reached
	while ((f1 = fgetc(fp1)) == (f2 = fgetc(fp2)) && f1 != EOF) {
		//printf("f1: %c f2: %c\n", f1, f2);
		
		// Store lines of each file, restarting on new line
		if (f1 == '\n') {	
			i1 = 0;
			i2 = 0;
		}
		else {	
			line1[i1++] = f1;
			
			line2[i2++] = f2;
		}
	}
	
	line1[i1] = '\0';
	line2[i2] = '\0';
	
	if (f1 == EOF && f2 == EOF) {
		printf("files are same");
		return 0;
	}
	
	while (f1 != EOF && f1 != '\n') {	// Lines are not the same, get rest of the line
		line1[i1++] = f1;
		f1 = fgetc(fp1);
	}
	line1[i1] = '\0';

	while (f2 != EOF && f2 != '\n') {	// Lines are not the same, get rest of the line
		line2[i2++] = f2;
		f2 = fgetc(fp2);
	}
	line2[i2] = '\0';
	
	printf("line1: %s\n", line1);
	printf("line2: %s\n", line2);

	fclose(fp1);
	fclose(fp2);

	return -1;
}