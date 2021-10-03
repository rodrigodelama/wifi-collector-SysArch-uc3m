//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

//Added the C libraries we needed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //to include sleep() function

//Added our own libraries
#include "../incl/arrays.h"
#include "../incl/string.h"
#include "../incl/cells.h"


//Declared future functions to be used
void print_menu();
int ask4num(int min, int max, char message[]);

int main (int argc, char *argv[]) {

	//Initially clean the console
	system("clear");
   
	do {
        print_menu();

    	switch (ask4num(1, 10, "Option: ")) {
	   		case 1:
			   //TODO: quit function
	   			printf("Are you sure you want to exit? [y/n]: ");
				char result;
				scanf("%c", &result);

				switch (result) {
					case 'y': system("exit");
					case 'Y': system("exit");
					/* code */
				
					default:
						break;
				}

	   		case 2:
			   //TODO: collect data from text files
				system("clear");


				break;
	   
	   		case 3:
				system("clear");
				break;
	   
	   		case 4:
				system("clear");
				break;
	   
	   		case 5:
				system("clear");
				break;
	   
	   		case 6:
				system("clear");
				break;
	   
	   		case 7:
				system("clear");
				break;
	   
	   		case 8:
				system("clear");
			   	break;
	   
	   		case 9:
			   //TODO: display the desired cell
				system("clear");
			   	break;

	   		case 10:
			   //TODO: display all cells
				system("clear");
			   	break;

	   		default:
				system("clear");
	   			printf("\nError: please input a number between 1-10\n\n");
				break;
        }

	} while(1);

   return 0;
}

// Prints the menu on the terminal
void print_menu() {
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

//NOTES

	//readline
	//to read lines use either getline or fgets (the latter is crossplatform)
	
	//fopen to open files
	//
	//
	//think about what files we actually need to read
	//

	//	also think about how we are going to read the text


// Receive the number that represents the chosen option

int ask4num(int min, int max, char message[]) {
    int option;
    char inputString[20]; //to prevent stack smashing

    printf("%s", message);

    do {
        scanf("%s", inputString);
        option = atoi(inputString); //atoi converts a string to an integer
        if (option < min || option > max) {
			printf("Error: please input a number between %d-%d\n", min, max);
			sleep(2);
			break;
		}
    } while (option < min || option > max);

    return option;
}


//sprintf

//we dont need channel we need the number
// check strtok_2.c

//"Cell %\nAddress: %s\n...."
//finish the format to read from the text files

//dont read line by line
// READ BY FORMAT