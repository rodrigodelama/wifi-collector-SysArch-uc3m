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
#include "../incl/linked_list.h"
//#include "../incl/main.h"

Node *insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE])
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->cell_n = cell_n;
    strcpy(node->MAC_Address, MAC_Address);
    strcpy(node->ESSID, ESSID);
    strcpy(node->mode, mode);
    node->channel = channel;
    strcpy(node->encryption, encryption);
    strcpy(node->quality, quality);
    strcpy(node->frequency, frequency);
    strcpy(node->signal_lvl, signal_lvl);
    node->next = NULL;

    return node;
    
    //printf("\n  %d", position); //debugging

    printf("\nData read from info_cell_%d.txt (added to position %d of the list)", cell_n, num_cell_ND);
    printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
            node->cell_n, node->MAC_Address,
            node->ESSID, node->mode,
            node->channel, node->encryption,
            node->quality, node->frequency,
            node->signal_lvl);
    num_cell_ND++;
    
    return node;
}

//Display option meant to print data from the requested, or all cells onto the commandline
void display_ind_cell(Node *head)
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
void display_all(Node *head)
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
