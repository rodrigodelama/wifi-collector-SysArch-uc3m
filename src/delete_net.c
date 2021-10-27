//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>

//#include"../incl/cells.h"
#include"../src/cells.c"

void delete_net(char net[], cell *cells)
{
   int counter = 0;
   
   for(int i = 0; i < c_index; i++)
   {
      if(net == cells[i].ESSID)
      {
         free(cells[i]);
      }
   }
}