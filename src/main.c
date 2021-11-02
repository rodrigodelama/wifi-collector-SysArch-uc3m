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



int main (int argc, char *argv[])
{
int index_c = 0;
int *ptr = &index_c;
	//Initially clean the console
	system("clear");
   
   	//Creating our dynamic array
	cell *cells = (cell*) calloc(INIT_SIZE, sizeof(cell)); //calloc() makes a mem allocation w all 0's
	do
	{
        print_menu();

    	switch (ask_num(1, 10, "Option: "))
		{
			//Quit function
	   		case 1:
	   			printf("\nAre you sure you want to exit? [y/n]: ");
				char result = getchar();
				quit(result);
				break;

			//Collects data from text files
	   		case 2:
				//index_c = collect_data(cells);
				collect_data(cells,ptr);
				//printf("%d", *ptr);
				/*if (*ptr != 0 && *ptr % INIT_SIZE == 0)
    			{
        			printf("\n(Allocated another 5 positions to the Dynamic Array)\n");
        			cells = (cell*) realloc(cells, (*ptr + INIT_SIZE)*sizeof(cell)); //mem address, data to realloc
    			}*/
				break;
	   
	   		case 3:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(4);
				system("clear");
				break;
	   
	   		case 4:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(4);
				system("clear");
				break;
	   
	   		case 5:
			   	printf("\nIndicate the ESSID (use ""):");
				 //  scanf(%s,net[]);
				//delete_net(char net[],cells);
			   	
				system("clear");
				break;
	   
	   		case 6:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(4);
				system("clear");
				break;
	   
	   		case 7:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			  	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(4);
				system("clear");
				break;
	   
	   		case 8:
			   	//To be implemented in later versions
			   	printf("\nThis functionality is not yet available!\n");
			   	printf("It will be implemented in later versions, see you then!\n");
			   	sleep(4);
				system("clear");
			   	break;
	   		
			//Displays only the desired cells by the user
	   		case 9:
				printf("\nIndicate the number of the cell for which you want to know its information (1 - 21): ");
				display_ind_cell(cells);
				system("clear");
			   	break;

			//Displays all scanned data
	   		case 10:
			   	display_all(cells, ptr);
				printf("\n\nPress any key to return to the main menu: ");
					char wait_for_key = getchar();
					system("clear");
			   	break;

	   		default:
				system("clear");
	   			printf("\nPlease input a number between 1-10\n\n");
				break;
        }
	} while(1); //while true

	free(cells);
   	return 0;
}

void print_menu()
{
	printf("[2021] SUCEM S.L. Wifi Collector\n");
	printf("  [ 1] wificollector_quit\n");
	printf("  [ 2] wificollector_collect\n");
	printf("  [ 3] wificollector_show_data_one_network\n");
	printf("  [ 4] wificollector_select_best\n");
	printf("  [ 5] wificollector_delete_net\n");
   	printf("  [ 6] wificollector_sort\n");
   	printf("  [ 7] wificollector_export\n");
   	printf("  [ 8] wificollector_import\n");
   	printf("  [ 9] wificollector_display\n");
   	printf("  [ 10] wificollector_display_all\n");
}

int ask_num(int min, int max, char message[])
{
    int option; //another idea is to use getchar()
    char inputString[20]; //20 to prevent stack smashing

    printf("%s", message);

    do
	{
        scanf("%s", inputString);
		getchar(); //meant to grab the 'enter' input and discard it

        option = atoi(inputString); //atoi converts a string to an integer

        if (option < min || option > max)
		{
			printf("\nError: please input a number between %d-%d\n", min, max);
			sleep(2);
			break;
		}
    } while (option < min || option > max);

    return option;
}
