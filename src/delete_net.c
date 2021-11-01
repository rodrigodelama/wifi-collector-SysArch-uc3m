//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>

//#include"../incl/cells.h"
#include"../src/cells.c"

void delete_net(char net[], cell *cells, int *ptr)
{
   int counter = 0;
   cell **cell_t_dlt;
   cell_t_dlt = &cells;
   for(int i = 0; i < c_index; i++)
   {
      if(net == cells[i].ESSID)
      {
         for(int j=i;i < c_index; j++)//movement of the pointers when deleting
         {
         *cell_t_dlt = &cells[j+1];
   
   
         }
         //free(&cell_t_dlt[i]);
         c_index--;
      }
   }
}