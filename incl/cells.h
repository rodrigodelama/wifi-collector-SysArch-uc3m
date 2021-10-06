//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#ifndef CELLS_H
#define CELLS_H

#define CELL_SIZE 80 //Fixed array size

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

struct cell_st info_cell_01[80];
struct cell_st info_cell_02[80];
struct cell_st info_cell_03[80];
struct cell_st info_cell_04[80];
struct cell_st info_cell_05[80];
struct cell_st info_cell_06[80];
struct cell_st info_cell_07[80];
struct cell_st info_cell_08[80];
struct cell_st info_cell_09[80];
struct cell_st info_cell_10[80];
struct cell_st info_cell_11[80];
struct cell_st info_cell_12[80];
struct cell_st info_cell_13[80];
struct cell_st info_cell_14[80];
struct cell_st info_cell_15[80];
struct cell_st info_cell_16[80];
struct cell_st info_cell_17[80];
struct cell_st info_cell_18[80];
struct cell_st info_cell_19[80];
struct cell_st info_cell_20[80];
struct cell_st info_cell_21[80];

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
