#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
//worked with Jake Carpenter

//functions intialization
void helpguide();
void reverser(char *string);
int printer(int argc, char** argv, int sleeptimer, int rflag, FILE *file);

//main function
int main (int argc, char** argv){
	//initialization of variables
	FILE *file;
	int rflag = 0;
	int dflag = 0;
	char *dvalue = NULL;
 	int c;
	int index;
	int sleeptimer = 0;
	//opterr = 0;
 	while ((c = getopt (argc, argv, "hrd:f:")) != -1)
	// this while loop allows the acceptance of arguements when running a program
   	switch (c){
    		case 'h':
		//this prints the help information for the program
			helpguide();
			return 1;
        		break;
      		case 'r':
		//this sets the r flag to one so that the text in the lines will reverse
        		rflag = 1;
        		break;
      		case 'd':
		//this sets the sleeptimer
			dvalue=optarg;
			sleeptimer=atoi(dvalue);
			dflag=1;
        		break;
      		case '?':
        		if (optopt == 'd')
          			fprintf (stderr, "Option -d requires an argument.\n");
        		else
          			fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        		return -1;
      		default:
        		abort ();
	}

	if (optind < argc){
		int id =1;
		printf("Parent Process: %d\n", getpid());	
	//if there is multiple arguemnts, it will read them one by one
		for (index= optind; index < argc; index++){
			if (id != 0){
				id=fork();
			}
			else {
				break;
			}
		}
		if (id == 0){
	                while (optind < argc && *argv[optind] != '-'){
        	        //      exists(argv[optind]);
                	        printer(argc, argv, sleeptimer, rflag, file);
                       		optind++;
               		}       

		}

		waitpid(-1,NULL,0);	
	}
	else {
		printer(argc, argv, sleeptimer, rflag, NULL);
	}
	return 0;
	
}
void helpguide(){
	printf("\nTHEY SAID '-h', BRING OUT THE SPIRIT OF ST. LOUIS ! ! ! \n\n");
	printf(" -r -> outputs text lines in reverse.\n");
	printf(" -d <integer> -> allows for  optional time delay function.\n\n");
}

void reverser(char *string){
        int length = strlen(string);
        int middle = length / 2;
        char temp;
        for (int i = 0; i < middle; i++){
                temp=string[i];
                string[i] = string[length - i - 1];
                string[length - i - 1] = temp;
        }
        printf("%d: %s\n\n",getpid(), string);
}

int printer(int argc, char** argv, int sleeptimer,int rflag, FILE *file){
        char line[100];
	char *result;
	if (optind < argc){
		file = fopen(argv[optind], "r");		
	}

        // fopen returns 0, the NULL pointer, on failure 
        if ( file == 0 )
        {
		while (!feof(stdin)){
		 	if ((result = fgets(line,100,stdin)) != NULL){
				printf("%d: %s",getpid(), line);
			}
			else
				return -1;		
                        sleep(sleeptimer);
			if (rflag == 1){
                        	reverser(line);
			}
			sleep(sleeptimer);
		}

        }
        else 
        {
                while  (fgets(line, sizeof(line), file )){
                        //this while loop prints line by line
                        //we also use our sleeptimer to pause for each line
                        //the reverser function is used to reverse the line
                        printf( "%d:%s",getpid(), line );
                        sleep(sleeptimer);
			if (rflag == 1){
                        	reverser(line);
			}
                        sleep(sleeptimer);
                }
                fclose( file ); 
        }
	return 0;
}
