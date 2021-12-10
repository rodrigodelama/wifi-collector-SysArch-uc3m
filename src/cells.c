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

//Initialize our Linked List
//head is the first node of our list
Node *head = NULL;


//Prints data from the requested cell
void display_ind_cell()
{
    int num_cell_to_display = ask_num(1, 21, " "); //registration of the cell to display
    Node *ptr;
    for (ptr = head; ptr != NULL; ptr = (*ptr).next)
    { 
        if (ptr->data.cell_n == num_cell_to_display)
        {
            printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                ptr->data.cell_n, ptr->data.MAC_Address,
                ptr->data.ESSID, ptr->data.mode,
                ptr->data.channel, ptr->data.encryption,
                ptr->data.quality, ptr->data.frequency,
                ptr->data.signal_lvl);
        } else {
            printf("\nThis cell has not been recorded yet, please try another cell number");
            sleep(2);
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
            display_ind_cell(head);
      
        case 'n':
        case 'N':
        break;
    }
}   

//Prints all saved cells
void display_all()
{    
    Node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("\nCell %d: %s %s %s %d %s %s %s000 %s", 
                ptr->data.cell_n, ptr->data.MAC_Address,
                ptr->data.ESSID, ptr->data.mode,
                ptr->data.channel, ptr->data.encryption,
                ptr->data.quality, ptr->data.frequency,
                ptr->data.signal_lvl);
    }   
}
