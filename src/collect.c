//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Declaration of our libraries
#include "../incl/cells.h"
#include "../incl/string.h"

//TODO: Deprecated - To be removed in future versions

int ask_cell_num(int min, int max, char message[]) {
    int option; //another idea is to use getchar()
    char inputString[20]; //20 to prevent stack smashing

    printf("%s", message);

    do
	{
        scanf("%s", inputString);
		getchar(); //is meant to grab the 'enter' input and discard it

        option = atoi(inputString); //atoi converts a string to an integer

        if (option < min || option > max)
		{
			printf("\nError: please input a valid cell number (%d-%d): ", min, max);
			sleep(2);
		}
    } while (option < min || option > max);

    return option;
}

void get_cell_data()
{
    char format[9][MAX_STRING_SIZE] = {"%s %s", "%*s %s", "%*[^:]: %s", "%*[^:]: %s", "" }; //TODO: FINISH format
}

void collect_data()
{
    char cell_x[] = ask_cell_num(1, 21, "Please input the desired cell number (1-21): ");

    char filename[MAX_STRING_SIZE];
    char file_to_open[] = strcat(strcat(filename, cell_x), ".txt");

    FILE *of = fopen(file_to_open, "r");

    //fscanf(of, );


}


//possible switch for thr integration of the data
//bool get

//sprintf

//old - IGNORE
//cell_st.cell_X = ask_cell_num();
