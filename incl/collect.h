//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include "../incl/cells.h"

#ifndef COLLECT_H
#define COLLECT_H

int collect_data(cell *cells, int *ptr);
void cells_read(char filename[], cell **cells,int *ptr);
int ask_cell_num(int min, int max, char message[]);

#endif
