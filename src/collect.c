#include <stdio.h>

//Declaration of our libraries
#include "../incl/cells.h"

void ask_cell_num()
{
    int num;
    do
    {
        printf("What cell do you want to collect? (1 - 21): \n");
        scanf("%d", &num); 
        
        if (num < 1 || num > 21)
            printf("Error: Invalid cell option\n"); 

    } while (num < 1 || num > 21);
    
    //once the cell number has been registered we save it 

    a.cell_X = num;
    
}

//old - IGNORE
//cell_st.cell_X = ask_cell_num();
