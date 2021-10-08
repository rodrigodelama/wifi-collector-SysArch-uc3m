#include <stdio.h>
#include <string.h> 

#include "../incl/cells.h"
#include "../incl/sizes.h"

int c_index = 0;

//array of structs to 
//struct cell_st data[ARRAY_SIZE];

int position_tracker[20][ARRAY_SIZE];

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE])
{
    if (c_index < ARRAY_SIZE)
    {
        //Add data to the structs
        cells[c_index].cell_n = cell_n;
        strcpy(cells[c_index].MAC_Address, MAC_Address);
        strcpy(cells[c_index].ESSID, ESSID);
        strcpy(cells[c_index].mode, mode);
        cells[c_index].channel = channel;
        strcpy(cells[c_index].encryption, encryption);
        strcpy(cells[c_index].quality, quality);
        strcpy(cells[c_index].frequency, frequency);
        strcpy(cells[c_index].signal_lvl, signal_lvl);
    
        //Add structs to storage array
        //data[c_index] = cells[c_index];

    //TODO:
        //Track the positions of each Cell's data
        //position_tracker[cell_n - 1][c_index];

        printf("\n  %d", c_index);
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
                cells[c_index].cell_n, cells[c_index].MAC_Address,
                cells[c_index].ESSID, cells[c_index].mode,
                cells[c_index].channel, cells[c_index].encryption,
                cells[c_index].quality, cells[c_index].frequency,
                cells[c_index].signal_lvl);

    c_index++;
    } else {
        printf("Cell Storage Array is full, please restart the program to reset the memory.");
    }
}

void display(int n)
{
    
}

void display_all()
{    
    for (int i = 0; i < c_index; i++)
    {
        printf("Cell %d: %s %s %s %d %s %s %s000 %s\n", 
                cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
    }   
}
