//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#include "../incl/cells.h"

void delete_net()
{
   extern Node *head;

   printf("\nIndicate the ESSID (use \"\"): ");
		char net[MAX_STRING_SIZE];
	   scanf("%s", net); //net is the name of the ESSID we want to find in the list

   //int counter = num_cell_ND;
   
   /**
   Node *ptr;
   if(head != NULL && strcmp(net, head->data.ESSID) == 0)
   {
      Node *tmp = head->next;
      free(head);
      head = tmp;
   }

   int i = 0;

   for(ptr = head; ptr->next == NULL; ptr = ptr->next)
   { 
      i++;
      if(strcmp(net, ptr->next.ESSID) == 0)
      {
         Node *tmpb = ptr->next->next;
         printf("Found ESSID %s at position %d\n\n", net, i);
         free(ptr->next);
         ptr->next = tmpb;

         num_cell_ND--;
      }
   }

   if(counter == num_cell_ND)
   {
      printf("No such ESSID found\n\nDo you want to delete another ESSID? [y/n]: ");
      char choice = getchar();
      switch (choice)
      {
         case 'Y':
         case 'y':
            delete_net();
         break;

         case 'N':
         case 'n':
            system("clear");
         break;

         default:
            printf("\nError: input was not valid, try again\n");
            sleep(4);
            system("clear");
         break;
      }
   }
    */

   delete_node(&head, net);
}
