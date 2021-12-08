//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#include"../incl/cells.h"

cell_list delete_net(cell_list head)
{
   printf("\nIndicate the ESSID (use \"\"): ");
		char net[MAX_STRING_SIZE];
	   scanf("%s", net); //net is the name of the ESSID we want to find in the list

   int counter = num_cell_ND;
   
   struct cell *ptr;
   if(head != NULL && strcmp(net, head->ESSID) == 0)
   {
      struct cell *tmp = head->next;
      free(head);
      head = tmp;
   }

   int i = 0;

   for(ptr = head; ptr != NULL; ptr = ptr->next)
   { 
      i++;
      if(strcmp(net, (*ptr).next->ESSID) == 0)
      {
         struct cell *tmpb = ptr->next->next;
         printf("Found ESSID %s at position %d\n\n", net, i);
         free(ptr->next);
         ptr->next = tmpb;
         //the double for is used in case there are multiple hits for the desired ESSID to be deleted
         num_cell_ND--;
      }
      
      //cells[position] = NULL;
   
   }

   if(counter == num_cell_ND)
   {
      printf("No such ESSID found\n\nDo you want to delete another ESSID? [y/n]: ");
      char choice = getchar();
      switch (choice)
      {
         case 'Y':
         case 'y':
            delete_net(head);
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

   /*
   extra comfort code to be completed on next submission
   */
   return head;
}
