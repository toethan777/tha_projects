#include <stdio.h>

int main(int argc, char* argv[]){
	//initialize variables
	char currentChar ='\0', prevChar = '\0';
	int currentRunLength=0, maxHrun=0, maxTrun=0;
	//initialize prevChar with stdin
	prevChar = getc(stdin);

	while (!feof(stdin)){
		//while not at the end of a file...
		currentChar = getc(stdin);

		if (currentChar !='T' && currentChar !='H'){
			continue;
			//skips over characters other than T and H
			//given something like two X's in a row,
			//it would not count them
			//nor would it set the current character to the previous character
		}

		if (currentChar == prevChar && currentChar == 'H'){
			currentRunLength++;
			//if the previous character is equal to the current character
			//and the current character is H
			//add to currentRunLength
			if (currentRunLength > maxHrun){
				//also if the current Run length exceeds the maxHrun length
				//add to max runHrun
				maxHrun++;
			}
		}

		if (currentChar == prevChar && currentChar == 'T'){
			currentRunLength++;
			//if the previous character is equal to the current character
			//and the current character is T
			//add to currentRunLength
			if (currentRunLength > maxTrun){
				//also if the current Run length exceeds the maxTrun length
				//add to max runTrun
				maxTrun++;
			}
		}

		if (currentChar != prevChar){
			//if the previous character is not equal to the current character,
			//set the current length to one
			currentRunLength = 1;
		}
		prevChar = currentChar;
		//we set the previous character to the current character for the next loop
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

