/**
 * Gorka Bernad - 100451457@alumnos.uc3m.es
 * Rodrigo De Lama - 100451775@alumnos.uc3m.es
 * 
 * cells.h:
 * - declares our dynamic array of structures of type cell_st
 * - declares the global int value position, to be used to track our position when traversing the array
 * - declares methods to: insert a new cell, display a specific individual cell and< to display all recorded cell
 */

#ifndef CELLS_H
#define CELLS_H

#include "../incl/dependencies.h"

typedef struct cell
{
    int cell_n;
    char MAC_Address[LINE_SIZE];
    char ESSID[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char encryption[LINE_SIZE];
    char quality[LINE_SIZE];
    char frequency[LINE_SIZE];
    char signal_lvl[LINE_SIZE];
    struct cell *next;

} *cell_list;

struct cell *head;

int num_cell_ND;

cell_list insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell_list head);
void display_ind_cell(cell_list head);
void display_all(cell_list head);

int ask_num(int min, int max, char message[]);

#endif
