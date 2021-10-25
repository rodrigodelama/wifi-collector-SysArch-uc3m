//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../incl/cells.h"
#include "../incl/main.h"
#include "../incl/sizes.h"

int c_index = 0;

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell *cells)
{
    //TODO: finish implementing DYNAMIC ARRAYS
    if (c_index != 0 && c_index % INIT_SIZE == 0)
    {
        cells = (cell*) realloc(cells, (c_index + INIT_SIZE)*sizeof(cell)); //mem address, data to realloc
        printf("(Allocated another 5 positions to the Dynamic Array)\n");
    }

    //Add data to the structs
    cell_n = (intptr_t) &cells[c_index].cell_n; //casting - https://stackoverflow.com/questions/22624737/casting-a-pointer-to-an-int
    strcpy(cells[c_index].MAC_Address, MAC_Address);
    strcpy(cells[c_index].ESSID, ESSID);
    strcpy(cells[c_index].mode, mode);
    channel = (intptr_t) &cells[c_index].channel;
    strcpy(cells[c_index].encryption, encryption);
    strcpy(cells[c_index].quality, quality);
    strcpy(cells[c_index].frequency, frequency);
    strcpy(cells[c_index].signal_lvl, signal_lvl);
    
    //printf("\n  %d", c_index); //debugging

    printf("\nData read from info_cell_%d.txt (added to position %d of the array)", cell_n, c_index);
    printf("\nCell %ls: %s %s %s %ls %s %s %s000 %s\n", 
            &cells[c_index].cell_n, cells[c_index].MAC_Address,
            cells[c_index].ESSID, cells[c_index].mode,
            &cells[c_index].channel, cells[c_index].encryption,
            cells[c_index].quality, cells[c_index].frequency,
            cells[c_index].signal_lvl);
}

// Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell(cell *cells)
{
    int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
    int counter = 0;
    for (int i = 0; i < LINE_SIZE; i++)
    {    
        if (cells[i].cell_n == num_cell_to_display)
        {
        printf("\nCell %ls: %s %s %s %ls %s %s %s000 %s", 
                &cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                &cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
        }
        
        if(cells[i].cell_n != num_cell_to_display)
        counter++;
        
        if (counter == 80)
        {
            printf("\nThis cell was not scanned yet, please scan it in option 2 in the main menu\n");  //Print in case the selected cells haven't been implemented
            break;
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

        //TODO: MISSING DEFAULT TO RE-LOOP
        //default:
            //code the while that shall englobe the switch
    }
}   

//Display option to print all data saved
void display_all(cell *cells)
{    
    for (int i = 0; i < c_index; i++)
    {
        printf("\nCell %ls: %s %s %s %ls %s %s %s000 %s", 
                &cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                &cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
    }   
}
