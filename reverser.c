#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv){
//accepts arguements
//we need at least three of them to start the program...
// 1) executable
// 2) sleeptimer variable
// 3) textfile
        if (argc != 3){
                //as seen here if you don't have three arguements, it wont start the c magic
                printf("You did not feed me the correct arguements, I will perish now\n");
                return 0;
        }
        //arguement 2 will store an integer so I shall make sure it does that
        int sleeptimer=atoi(argv[1]);

        //arguement 3 is the text file, so we must make sure we are reading a text file
        FILE *file = fopen(argv[2], "r");

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
                int x;
                char line[1000];
                int lineNo = 0;
                while  ( ( x = fgetc( file ) ) != EOF ){
                        //    printf( "%c", x );
                        // line above just prints everything...
                        if(fgets(line, sizeof(line), file )){
                                printf("%s",line);
                        }
                }
                fclose( file ); 
        }
    return 0;
}
