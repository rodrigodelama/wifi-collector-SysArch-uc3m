//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include "../incl/cells.h"

#ifndef COLLECT_H
#define COLLECT_H

//void ask_cell_num_OLD();
int collect_data(cell *cells);
void cells_read(char filename[], cell *cells);
int ask_cell_num(int min, int max, char message[]);

#endif
