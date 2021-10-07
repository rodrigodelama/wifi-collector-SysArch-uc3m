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

/*struct cell_data*/ void get_cell_data(char filename[]) //also input an array
{
    //* between % and data type means IGNORE
    // %*[^:]:
    //TODO: FINISH format
    char format[9][MAX_STRING_SIZE] = { "%*s %s:", "%*s %s", "%*[^:]: %s", "%*[^:]: %s", "%*[^:]: %s",
                                        "%*[^:]: %s", "%*[^=]= %s", "%*[^:]: %s000", "%*[^=]= %s" }; 

    
    FILE *of = fopen(filename, "r");

    char tempTarget[MAX_STRING_SIZE];

    //run fscanf loops until EOF is thrown
    //use do while
    //fscanf grabs each line following a format, use a for
    //fscanf(target, format, source);
    
    //FILE *wf = fopen("./input_files/cells/test.txt", "w+");

    //create a struct

    fscanf(of, format[0], tempTarget);

    printf("%s \n", tempTarget);
    sleep(4);

    //return cell_data;
}

void collect_data()
{
// TODO: FIX
    int selection = ask_cell_num(1, 21, "Please input the desired cell number (1-21): ");

    char cell_x[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_x, "%d", selection);

    //Concatenating strings together to form the filename
    char filename[] = {"./input_files/cells/info_cell_"};
    strcat(filename, cell_x);
    strcat(filename, ".txt");

    printf("%s\n\n", filename);
    sleep(3);

    get_cell_data(filename);

    //create an array to know if cells were already searched

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
