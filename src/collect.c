#include<stdio.h>
//Declaration of our librarys
#include "../incl/cells.h"

int ask_cell_num(){
    int num;
    do{
      printf("What cell do you want to collect? (1 - 21): \n");
      scanf("%d", &num); 
        
        if(num<1||num>21)
            printf("ERROR--Wrong cell option\n"); 

    }while (num<1||num>21);
    
 return num;
    
}
cell_st.cell_X = ask_cell_num();


