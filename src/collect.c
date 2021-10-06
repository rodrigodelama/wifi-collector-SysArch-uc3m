#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h> 

//Declaration of our libraries
#include "../incl/cells.h"

//TODO: Deprecated - To be removed in future versions

/*
void ask_cell_num_OLD()
{
    int num; //user input number
    do
    {
        printf("What cell do you want to collect? (1 - 21): \n");
        scanf("%d", &num); 
        
        if (num < 1 || num > 21)
            printf("Error: Invalid cell option\n"); 

    } while (num < 1 || num > 21);
    
    //once the cell number has been registered we save it 

    //a.cell_X = num;
    
}
*/

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

//posible switch for thr integration of the data
//bool get

//sprintf

//old - IGNORE
//cell_st.cell_X = ask_cell_num();

//MAC (Media acces control)(Draft)
//this command could be
void MAC_SET_UP(){
     char Mac_input[16];
     do
     {
        scanf("%s",Mac_input);
        
        if(MAC_check(Mac_input)==1)
            printf("\nError: please input a valid cell number");

        //possible integration per file through a switch
     
    } while (!MAC_check(Mac_input));
    
     
}

//ESSID Selector(draft)
void ESSID_SET_UP(){

    
}

