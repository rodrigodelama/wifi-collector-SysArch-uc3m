//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <string.h> 

#include "../incl/cells.h"
#include "../incl/sizes.h"
#include "../incl/main.h"

int c_index = 0;

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
    
        //printf("\n  %d", c_index); //debugging
        printf("\nData read from info_cell_%d.txt (added to position %d of the array)", cell_n, c_index);
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
                cells[c_index].cell_n, cells[c_index].MAC_Address,
                cells[c_index].ESSID, cells[c_index].mode,
                cells[c_index].channel, cells[c_index].encryption,
                cells[c_index].quality, cells[c_index].frequency,
                cells[c_index].signal_lvl);
    c_index++;
    } else {
        printf("\n\nCell Storage Array is full, please restart the program to reset the memory.");
    }
}

// Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell()
{
   int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
   int counter = 0;
    for (int i = 0; i < LINE_SIZE; i++)
    {    
        if (cells[i].cell_n == num_cell_to_display)
        {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
        }
        
        if(cells[i].cell_n != num_cell_to_display)
        counter++;
        
        if (counter == 80){
            printf("\nThis cell was not scanned yet, please scan it in option 2 in the main menu\n");  //Print in case the selected cells haven't been implemented
            break;}
    
    }
    printf("\n\nDo you want to read another collection of cells? [y/n]: ");
        char result = getchar();
        switch (result)
        {
            case 'y':
            case 'Y': 
                printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
                display_ind_cell();
      
            case 'n':
            case 'N':
                break;

            //MISSING DEFAULT TO RELOOP
        }

}   

//Display option to print all data saved
void display_all()
{    
    for (int i = 0; i < c_index; i++)
    {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                cells[i].cell_n, cells[i].MAC_Address,
                cells[i].ESSID, cells[i].mode,
                cells[i].channel, cells[i].encryption,
                cells[i].quality, cells[i].frequency,
                cells[i].signal_lvl);
    }   
}
