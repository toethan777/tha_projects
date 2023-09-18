#include <stdio.h>
int main(int argc, char **argv){
	//initialize variables
	char currentChar ='\0', prevChar = '\0';
	int currentRunLength=0, longHrun=0, longTrun=0;

	while (!feof(stdin)){
		currentChar = getc(stdin);
		printf("C: %c\n",currentChar);

		if (currentChar !='T'&& currentChar !='H'){
			prevChar = currentChar;	
			printf("P: %c\n",prevChar);
			continue;
		}

		else if (currentChar = prevChar && currentChar == 'H'){
			if (currentRunLength > longHrun){
				longHrun = ++longHrun;
				currentRunLength = ++currentRunLength;
			}
			prevChar = currentChar;	
			printf("P: %c\n",prevChar);
			continue;
		}

		else if (currentChar = prevChar && currentChar == 'T'){
			if (currentRunLength > longTrun){
				longTrun = ++longTrun;
				currentRunLength = ++currentRunLength;
			}
			prevChar = currentChar;	
			printf("P: %c\n",prevChar);
			continue;
		}

		else {
			currentRunLength = 1;
			prevChar = currentChar;	
			printf("P: %c\n",prevChar);		
			continue;
		}
	}	

	if (longTrun == longHrun){
		printf("B: %d\n", longTrun);
	}

	if (longTrun > longHrun){
		printf("T: %d\n", longTrun);
	}

	if (longTrun < longHrun){
		printf("H: %d\n", longHrun);
	}

	return 0;
}

