//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#ifndef _CELLS_H
#define _CELLS_H

#define CELL_SIZE 200 //Fixed array size

struct cell_st
{
    int cell_X;
    char MAC_Address[16];
    char ESSID[CELL_SIZE];
    char Mode[CELL_SIZE];
    int channel;
    char encryption[2];
    char quality[4];
    char frequency[8];
    char signal_lvl[7];
    
};

void print_X();
void print_all();

#endif
