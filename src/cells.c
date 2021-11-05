//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "../incl/cells.h"
#include "../incl/main.h"
#include "../incl/dependencies.h"

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell **cells)
{

    (*cells)[position].cell_n = cell_n;
    strcpy((*cells)[position].MAC_Address, MAC_Address);
    strcpy((*cells)[position].ESSID, ESSID);
    strcpy((*cells)[position].mode, mode);
    (*cells)[position].channel = channel;
    strcpy((*cells)[position].encryption, encryption);
    strcpy((*cells)[position].quality, quality);
    strcpy((*cells)[position].frequency, frequency);
    strcpy((*cells)[position].signal_lvl, signal_lvl);
    
    //printf("\n  %d", position); //debugging

    printf("\nData read from info_cell_%d.txt (added to position %d of the array)", cell_n, position);
    printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
            (*cells)[position].cell_n, (*cells)[position].MAC_Address,
            (*cells)[position].ESSID, (*cells)[position].mode,
            (*cells)[position].channel, (*cells)[position].encryption,
            (*cells)[position].quality, (*cells)[position].frequency,
            (*cells)[position].signal_lvl);
    position++;
}

//Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell(cell **cells)
{
    int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
    for (int i = 0; i < position; i++)
    {    
        /*
        if (cells[num_cell_to_display] == NULL)
        {
            printf("This cell has not been recorded yet, please try another cell number");
            sleep(2);
            break;
        }
        else */
        if ((*cells)[i].cell_n == num_cell_to_display)
        {
            printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                (*cells)[i].cell_n, (*cells)[i].MAC_Address,
                (*cells)[i].ESSID, (*cells)[i].mode,
                (*cells)[i].channel, (*cells)[i].encryption,
                (*cells)[i].quality, (*cells)[i].frequency,
                (*cells)[i].signal_lvl);
        }        
    }

    printf("\n\nDo you want to read another collection of cells? [y/n]: ");
    char result = getchar();
    switch (result)
    {
        case 'y':
        case 'Y': 
            printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
            display_ind_cell(cells);
      
        case 'n':
        case 'N':
        break;
    }
}   

//Display option to print all data saved
void display_all(cell **cells)
{    
    for (int i = 0; i < position; i++)
    {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                (*cells)[i].cell_n, (*cells)[i].MAC_Address,
                (*cells)[i].ESSID, (*cells)[i].mode,
                (*cells)[i].channel, (*cells)[i].encryption,
                (*cells)[i].quality, (*cells)[i].frequency,
                (*cells)[i].signal_lvl);
    }   
}
