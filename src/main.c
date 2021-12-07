//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

//Added the C libraries we needed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //to include sleep() function

//Added our own libraries
#include "../incl/main.h"
#include "../incl/quit.h"
#include "../incl/collect.h"
#include "../incl/cells.h"
#include "../incl/dependencies.h"
#include "../incl/delete_net.h"
#include "../incl/linked_list.h"

int main ()
{
	//position = 0;
	//int *ptr = &position;

	//Initially clean the console
	system("clear");
   
	//Initialize our Linked List
	//cells shall be the name of our list once again
	Node head;

   	//initiallizing our dynamic array
	head = (cell_list)malloc(sizeof(cell_list)); //calloc() makes a mem allocation w all 0's
	
	do
	{
		//printf("\n\nindex: %d\n\n", position); //debugging

        print_menu();

    	switch (ask_num(1, 10, "\n  Option: "))
		{
			//Quit function
	   		case 1:
	   			printf("\nAre you sure you want to exit? [y/n]: ");
				char result = getchar();
				quit(result);
				break;

			//Collects data from text files
	   		case 2:
				collect_data(head);
				break;
	   
	   		case 3:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(2);
				system("clear");
				break;
	   
	   		case 4:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(2);
				system("clear");
				break;
	   
	   		case 5:
				delete_net(head);
				break;
	   		case 6:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(2);
				system("clear");
				break;
	   
	   		case 7:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			  	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(2);
				system("clear");
				break;
	   
	   		case 8:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(2);
				system("clear");
			   	break;
	   		
			//Displays only the desired cells by the user
	   		case 9:
				printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
				display_ind_cell(head);
				system("clear");
			   	break;

			//Displays all scanned data
	   		case 10:
			   	display_all(head);
				printf("\n\nPress any key to return to the main menu: ");
					getchar(); //to grab enter
				system("clear");
			   	break;

	   		default:
				system("clear");
	   			printf("\nPlease input a number between 1-10\n\n");
				break;
        }
	} while(1); //while true
	struct cell *ptr = head;
	while(ptr != NULL){
	ptr = head->next;	
	free(head);
	head = ptr;
	}
   	return 0;
}
