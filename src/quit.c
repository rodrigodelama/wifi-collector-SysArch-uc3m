//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../incl/quit.h"

void quit (char result)
{
    switch (result)
    {
    	case 'y':
    	case 'Y': //No need to repeat sys exit or break on both y and Y
    		printf("\nGoodbye!\n");
    		sleep(2);
    	exit(0);

    	case 'n':
    	case 'N':
			system("clear");
    	break;

    	default:
    		printf("\nError: input was not valid, try again\n");
			sleep(1);
			system("clear");
    	break;
    }
}
