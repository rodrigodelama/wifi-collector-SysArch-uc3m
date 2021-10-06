//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#ifndef CELLS_H
#define CELLS_H

#define CELL_SIZE 80 //Fixed array size

struct cell_st
{
    int cell_X;
    char MAC_Address[CELL_SIZE];
    char ESSID[CELL_SIZE];
    char Mode[CELL_SIZE];
    int channel;
    char encryption[CELL_SIZE];
    char quality[CELL_SIZE];
    char frequency[CELL_SIZE];
    char signal_lvl[CELL_SIZE];
    
};

struct cell_st info_cell_01[CELL_SIZE];
struct cell_st info_cell_02[CELL_SIZE];
struct cell_st info_cell_03[CELL_SIZE];
struct cell_st info_cell_04[CELL_SIZE];
struct cell_st info_cell_05[CELL_SIZE];
struct cell_st info_cell_06[CELL_SIZE];
struct cell_st info_cell_07[CELL_SIZE];
struct cell_st info_cell_08[CELL_SIZE];
struct cell_st info_cell_09[CELL_SIZE];
struct cell_st info_cell_10[CELL_SIZE];
struct cell_st info_cell_11[CELL_SIZE];
struct cell_st info_cell_12[CELL_SIZE];
struct cell_st info_cell_13[CELL_SIZE];
struct cell_st info_cell_14[CELL_SIZE];
struct cell_st info_cell_15[CELL_SIZE];
struct cell_st info_cell_16[CELL_SIZE];
struct cell_st info_cell_17[CELL_SIZE];
struct cell_st info_cell_18[CELL_SIZE];
struct cell_st info_cell_19[CELL_SIZE];
struct cell_st info_cell_20[CELL_SIZE];
struct cell_st info_cell_21[CELL_SIZE];

/*

int Index_1 = 0;
int Index_2 = 0;
int Index_3 = 0;
int Index_4 = 0;
int Index_5 = 0;
int Index_6 = 0;
int Index_7 = 0;
int Index_8 = 0;
int Index_9 = 0;
int Index_10 = 0;
int Index_11 = 0;
int Index_12 = 0;
int Index_13 = 0;
int Index_14 = 0;
int Index_15 = 0;
int Index_16 = 0;
int Index_17 = 0;
int Index_18 = 0;
int Index_19 = 0;
int Index_20 = 0;
int Index_21 = 0;

*/

void print_X();
void print_all();

#endif
