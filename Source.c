#include <stdio.h>

int main() {

	FILE* fp;
	char buff[255];
	errno_t err;

	/* we create and open the file called "txt" with the file attribute ".txt" for reading and writing. This file MUST be in the same directory as your code! */

	err = fopen_s(&fp, "test.txt", "w+");
	fputs("This is testing for fputs...\n", fp);
	fprintf(fp, "This is testing for fprintf...\n");
	fprintf(fp, "Following will be all cubic numbers <= 1000...\n");
	for (int i = 1; i <= 10; i++) {
		fprintf(fp, "%d\n", i * i * i);
	}
	fclose(fp);

	printf(" File has been written\n");

	printf(" Now we read the same file\n");

	err = fopen_s(&fp, "test.txt", "r");

	for (int i = 0; i < 13; i++) {
		fgets(buff, 255, (FILE*)fp);
		printf(" %s\n", buff);
	} // end for loop

	fclose(fp);
	return 0;
} // end main