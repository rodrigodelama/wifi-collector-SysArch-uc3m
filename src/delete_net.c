//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../incl/cells.h"
//#include"../src/cells.c"

void delete_net(cell *cells, int *ptr)
{  char com_cste = '"';
   printf("\nIndicate the ESSID (use %c): ", com_cste);
					char net[MAX_STRING_SIZE];
				   scanf("%s", net);
   /*char net_chosen[sizeof(net)];
   strcpy(net_chosen,remove_extra(net));*/
   int counter = 0;
   cell **cell_t_dlt;
   cell_t_dlt = &cells;
   for(int i = 0; i < *ptr; i++)
   {
      if(strcmp(net,cells[i].ESSID)==0)
      {
         free(cell_t_dlt[i]); 
         printf("Found ESSID %s at position %d\n", net, i);
         for(int j=i;i < *ptr; j++)//movement of the pointers when deleting
         {
         cell_t_dlt[i] = &cells[j+1];  
         }
        (*ptr)--;
      } 
      counter++;
   }
   if(counter == (int)sizeof(cells)){
      printf("No net under that ESSID found\n Do you want to delete another net?[y,n]: ");
      char choice = getchar();
      switch (choice)
      {
      case 'Y':
      case 'y':
         delete_net(cells,ptr);
         break;
      case 'N':
      case 'n':
         system("clear");
         break;
      default:
         printf("\nError: input was not valid, try again\n");
            system("clear");
         break;
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