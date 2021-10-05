#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../incl/quit.h"

void quit(char result)
{
    switch (result)
    {
    	case 'y': //you dont need to repeat the sys exit or break
    	case 'Y':
    		printf("\nGoodbye!\n");
    		sleep(3);
    		exit(0);

    	case 'n':
    	case 'N':
    		break;

    	default:
			system("clear");
    		printf("\nError: input was not valid, try again\n");
    		sleep(3);
    		break;
    }
}
