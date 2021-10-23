//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#ifndef CELLS_H
#define CELLS_H

#include "../incl/sizes.h"

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
    char address[LINE_SIZE];
} cell_st;

//struct cell_st cells[LINE_SIZE];

cell_st *cells[LINE_SIZE] = (cell_st*) calloc(INIT_SIZE, sizeof(cell_st));

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE]);
void display_ind_cell();
void display_all();
int find_cell(char cell_n);

#endif
