#include <stdio.h>
#include <string.h>

#include "../incl/cells.h"
#include "../incl/sizes.h"

int index = 0;

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE])
{
    if (index < ARRAY_SIZE)
    {
        cells[index].cell_n[index] = cell_n;
        cells[index].MAC_Address[index] = MAC_Address;
        cells[index].ESSID[index] = ESSID;
        cells[index].mode[index] = mode;
        cells[index].channel[index] = channel;
        cells[index].encryption[index] = encryption;
        cells[index].quality[index] = quality;
        cells[index].frequency[index] = frequency;
        cells[index].signal_lvl[index] = signal_lvl;
    
    index++;
    } else {
        printf("Cell Storage Array is full, please restart the program to reset the memory.")
    }
}

void display(int n)
{

}

void display_all()
{
    
}
