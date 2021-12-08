//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../incl/cells.h"
#include "../incl/linked_list.h"
#include "../incl/dependencies.h"

int ask_num(int min, int max, char message[])
{
    int option;
    char inputString[20]; //20 to prevent stack smashing

    printf("%s", message);

    do
	{
        scanf("%s", inputString);
		getchar(); //is meant to grab the 'enter' input and discard it

        option = atoi(inputString); //atoi converts a string to an integer

        if (option < min || option > max)
		{
			printf("\nError: please input a valid cell number (%d-%d): ", min, max);
			sleep(2);
            break;
		}
    } while (option < min || option > max);

    return option;
}

node cells_read(char filename[], node head)
{
	FILE *of;

	int cell_n;
    char MAC_Address[LINE_SIZE];
    char ESSID[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char encryption[LINE_SIZE];
    char quality[LINE_SIZE];
    char frequency[LINE_SIZE];
    char signal_lvl[LINE_SIZE];

	of = fopen(filename,"r");

    if (of == NULL)
    {
      	fprintf(stderr, "The File: %s was not found.\n", filename);
	}
    else
    {
        while (fscanf(of, "Cell %d\nAddress: %s\nESSID:%[^\n]\nMode:%s\nChannel:%d\nEncryption key:%s\nQuality=%s\nFrequency:%s GHz\nSignal level=%s dBm\n",
                      &cell_n, MAC_Address, ESSID, mode, &channel, encryption, quality, frequency, signal_lvl) != EOF)
        {
	        head = insert_new_cell(cell_n, MAC_Address, ESSID, mode, channel, encryption, quality, frequency, signal_lvl, head);
        }
        fclose(of);
    }

    return head;
}

node collect_data(node head)
{
    int selection = ask_num(1, 21, "\nWhat cell do you want to collect? (1-21): ");

    char cell_n[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_n, "%d", selection);

    //Concatenating strings together to form the filename
    char filename[] = {"./input_files/cells/info_cell_"};
    strcat(filename, cell_n);
    strcat(filename, ".txt");

    head = cells_read(filename, head);

    printf("\nDo you want to add another access point? [y/n]: ");
				char result = getchar();
    switch (result)
    {
    	case 'y': //you dont need to repeat the sys exit or break
    	case 'Y':
            collect_data(head);
        break;
        
    	case 'n':
    	case 'N':
            system("clear");
    	break;

    	default:
    		printf("\nError: input was not valid, try again\n");
            system("clear");
    	break;
    }

    return head;
}   
