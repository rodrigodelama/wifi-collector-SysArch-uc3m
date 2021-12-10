//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../incl/cells.h"

Node *deleted = NULL;

void delete_net()
{
   extern Node *head;

   printf("\nIndicate the ESSID (use \"\"): ");
		char net[MAX_STRING_SIZE];
	   scanf("%s", net); //net is the name of the ESSID we want to find in the list

   delete_node(&head, net);
}
