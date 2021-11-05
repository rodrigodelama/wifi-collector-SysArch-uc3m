//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../incl/cells.h"

void delete_net(cell **cells)
{  
   //char com_cste = '"';
   printf("\nIndicate the ESSID (use \"): "/*, com_cste*/);
					char net[MAX_STRING_SIZE];
				   scanf("%s", net);

   int counter = position;
   cell **cell_t_dlt;
   cell_t_dlt = &cells;

   for(int i = 0; i < position; i++)
   {
      if(strcmp(net, (*cells)[i].ESSID) == 0)
      {
         *cell_t_dlt = &cells[i];
         printf("Found ESSID %s at position %d\n", net, i);
         for(int j = i; i < position; j++)//movement of the pointers when deleting
         {
            cells[j] = cells[j+1];  
         }
         free(cell_t_dlt[i]); 
         position--;
      } 
   }
   
   if(counter == position){
      printf("No net under that ESSID found\n Do you want to delete another net? [y/n]: ");
      char choice = getchar();
      switch (choice)
      {
         case 'Y':
         case 'y':
            delete_net(cells);
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