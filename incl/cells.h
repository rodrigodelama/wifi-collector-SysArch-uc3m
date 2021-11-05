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

typedef struct cell_st
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
} cell;

//560 bytes bc size of 7*LINE_SIZE + 8 bytes, 4 for each int

//creating our dynamic array of structs
cell *cells;

int position;

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE],
                     cell **cells);
void display_ind_cell(cell **cells);
void display_all(cell **cells);

#endif
