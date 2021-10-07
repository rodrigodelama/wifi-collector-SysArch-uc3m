//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Declaration of our libraries
#include "../incl/cells.h"
#include "../incl/sizes.h"

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
// TODO: FIX
    int selection = ask_cell_num(1, 21, "Please input the desired cell number (1-21): ");
    //int l = sizeof(selection);

    //char selection_str[l];

    char cell_x[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_x, "%d", selection);

    //itoa(selection, cell_x, 10);

    char filename[] = {"info_cell_"};
    strcat(filename, cell_x);
    strcat(filename, ".txt");

    printf("%s\n\n", filename);
    sleep(3);

    FILE *of = fopen(filename, "r");

    //fscanf(of, );


}


//possible switch for thr integration of the data
//bool get

//sprintf

//old - IGNORE
/*
int option = ask_cell_num(1,21, msg)
for(int I =0; i<Cell_line_SIZE; i++){
    if(cell_st[i].cell_X == option;)
    display(cell_st[i])
}
*/