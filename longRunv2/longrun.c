#include <stdio.h>

int main(int argc, char* argv[]){
	//initialize variables
	char currentChar ='\0', prevChar = '\0';
	int currentRunLength=0, maxHrun=0, maxTrun=0;
	prevChar = getc(stdin);
	printf("P:%c\n", prevChar);

	while (!feof(stdin)){
		//while not at the end of a file...
		currentChar = getc(stdin);

		if (currentChar !='T' && currentChar !='H'){
			continue;
		}

		if (currentChar == prevChar && currentChar == 'H'){
			if (currentRunLength > maxHrun){
				maxHrun++;
				currentRunLength++;
			}
		}

		if (currentChar == prevChar && currentChar == 'T'){
			if (currentRunLength > maxTrun){
				maxTrun++;
				currentRunLength++;
			}
		}

		if (currentChar != prevChar){
			currentRunLength = 1;
		}
		prevChar = currentChar;
		printf("P:%c\n", prevChar);
	}	

	if (maxTrun == maxHrun){
		printf("B: %d\n", maxTrun);
	}

	if (maxTrun > maxHrun){
		printf("T: %d\n", maxTrun);
	}

	if (maxTrun < maxHrun){
		printf("H: %d\n", maxHrun);
	}

	return 0;
}

