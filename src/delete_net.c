//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#include"../incl/cells.h"

void delete_net(cell **cells)
{
   printf("\nIndicate the ESSID (use \"\"): ");
		char net[MAX_STRING_SIZE];
	   scanf("%s", net);

   int counter = position;
   
   for(int i = 0; i < position; i++)
   {
      if(strcmp(net, (*cells)[i].ESSID) == 0)
      { 
         printf("Found ESSID %s at position %d\n\n", net, i);
         free(cells[i]);

         //the double for is used in case there are multiple hits for the desired ESSID to be deleted
         for(int j = i; j < position; j++) //shuffle of the pointers when deleting
         {
            (*cells)[j] = (*cells)[j+1];
         }

         position--;
      }
      
      //cells[position] = NULL;
   
   }
   /*
   if(counter == position)
   {
      printf("No such ESSID found\n\nDo you want to delete another ESSID? [y/n]: ");
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

   extra comfort code to be completed on next submission
   */
}
