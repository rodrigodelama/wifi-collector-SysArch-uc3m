/**
 * Gorka Bernad - 100451457@alumnos.uc3m.es
 * Rodrigo De Lama - 100451775@alumnos.uc3m.es
 * 
 * collect.h:
 * - declares functions to collect the info about the cell number to be inserted into the array,
 *   read the cell files, checks that the number is valid
 */

#include "../incl/cells.h"

#ifndef COLLECT_H
#define COLLECT_H

void collect_data();
void cells_read(char filename[]);
int ask_cell_num(int min, int max, char message[]);

#endif
