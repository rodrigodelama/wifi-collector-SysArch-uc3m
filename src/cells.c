//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "../incl/cells.h"
#include "../incl/collect.h"
#include "../incl/dependencies.h"
//#include "../incl/main.h"

cell_list insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell_list head)
{
    //this is for the next node after head
    if(head != NULL)
    {
        struct cell *new_cell;
        new_cell = (struct cell*)malloc(sizeof(struct cell*));
        new_cell->next = head;
        head = new_cell;
    }

    head->cell_n = cell_n;
    strcpy(head->MAC_Address, MAC_Address);
    strcpy(head->ESSID, ESSID);
    strcpy(head->mode, mode);
    head->channel = channel;
    strcpy(head->encryption, encryption);
    strcpy(head->quality, quality);
    strcpy(head->frequency, frequency);
    strcpy(head->signal_lvl, signal_lvl);
    
    //printf("\n  %d", position); //debugging

    printf("\nData read from info_cell_%d.txt (added to position %d of the list)", cell_n, num_cell_ND);
    printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
            head->cell_n, head->MAC_Address,
            head->ESSID, head->mode,
            head->channel, head->encryption,
            head->quality, head->frequency,
            head->signal_lvl);
    num_cell_ND++;
    
    return head;
}

//Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell(cell_list head)
{
    int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
    struct cell *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {    
        /*
        comfort code to be implemented later

        if (cells[num_cell_to_display] == NULL)
        {
            printf("This cell has not been recorded yet, please try another cell number");
            sleep(2);
            break;
        }
        else */
        if (ptr->cell_n == num_cell_to_display)
        {
            printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                ptr->cell_n, ptr->MAC_Address,
                ptr->ESSID, ptr->mode,
                ptr->channel, ptr->encryption,
                ptr->quality, ptr->frequency,
                ptr->signal_lvl);
        }        
    }

    printf("\n\nDo you want to read another collection of cells? [y/n]: ");
    char result = getchar();
    switch (result)
    {
        case 'y':
        case 'Y': 
            printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
            display_ind_cell(head);
      
        case 'n':
        case 'N':
        break;
    }
}   

//Display option to print all data saved
void display_all(cell_list head)
{    
    struct cell *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                ptr->cell_n, ptr->MAC_Address,
                ptr->ESSID, ptr->mode,
                ptr->channel, ptr->encryption,
                ptr->quality, ptr->frequency,
                ptr->signal_lvl);
    }   
}
