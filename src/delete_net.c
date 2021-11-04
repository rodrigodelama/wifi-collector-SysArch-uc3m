//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../incl/cells.h"
//#include"../src/cells.c"

void delete_net(char net[], cell *cells, int *ptr)
{  
   /*char net_chosen[sizeof(net)];
   strcpy(net_chosen,remove_extra(net));*/
   int counter = 0;
   cell **cell_t_dlt;
   cell_t_dlt = &cells;
   for(int i = 0; i < *ptr; i++)
   {
      if(strcmp(net,cells[i].ESSID))
      {
         printf("Found ESSID %s at position %d\n", net, i);
         free(cell_t_dlt[i]);
         for(int j=i;i < *ptr; j++)//movement of the pointers when deleting
         {
         *cell_t_dlt = &cells[j+1];  
         }
        (*ptr)--;
      }
   }
}

/*char remove_extra(char net[])
{
   char net_copy[sizeof(net)];
   strcpy(net_copy,net);
   for(int i = 0; i < sizeof(net); i++)//check the array
   {
      if(net[0] == net_copy[i+1])
      {
         net_copy[i+1] = NULL;
         break;
      }
      if(net[0] == net_copy[i])
      {
         for(int j = 0; j<sizeof(net); j++)
         {
         net_copy[j] = net[j+1];
         }
      }
   }
   return net_copy;*/