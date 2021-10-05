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
struct cell_st info_cell_01[200];
struct cell_st info_cell_02[200];
struct cell_st info_cell_03[200];
struct cell_st info_cell_04[200];
struct cell_st info_cell_05[200];
struct cell_st info_cell_06[200];
struct cell_st info_cell_07[200];
struct cell_st info_cell_08[200];
struct cell_st info_cell_09[200];
struct cell_st info_cell_10[200];
struct cell_st info_cell_11[200];
struct cell_st info_cell_12[200];
struct cell_st info_cell_13[200];
struct cell_st info_cell_14[200];
struct cell_st info_cell_15[200];
struct cell_st info_cell_16[200];
struct cell_st info_cell_17[200];
struct cell_st info_cell_18[200];
struct cell_st info_cell_19[200];
struct cell_st info_cell_20[200];
struct cell_st info_cell_21[200];

int Index_1 = 0;
int Index_2 = 0;
int Index_3 = 0;
int Index_4 = 0;
int Index_5 = 0;
int Index_6 = 0;
int Index_7 = 0;
int Index_8 = 0;
int Index_9 = 0;
int Index_10= 0;
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

void print_X();
void print_all();

#endif
