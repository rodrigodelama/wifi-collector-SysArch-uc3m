//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../incl/cells.h"
#include "../incl/dependencies.h"


int ask_cell_num(int min, int max, char message[])
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
		}
    } while (option < min || option > max);

    return option;
}

void cells_read(char filename[], cell *cells)
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
            //FIXME: Data is not being added correctly to the dynamic array
	        if(position != 0 && position % INIT_SIZE == 0)
            {
                printf("\n\nsize of cell (struct): %ld\n\n", sizeof(cell));
                printf("\n\nposition: %d\n\n", position);
                printf("\n\nsize of cells (dyn array): %ld\n\n", sizeof(*cells));

                printf("\n(Allocated another 5 positions to the Dynamic Array)\n");
                cells = (cell*) realloc(cells, (position + INIT_SIZE)*sizeof(cell)); //mem address, data to realloc

                printf("\n\nexpansion: %ld\n\n", (position + INIT_SIZE)*sizeof(cell));
            }
            insert_new_cell(cell_n, MAC_Address, ESSID, mode, channel, encryption, quality, frequency, signal_lvl, &cells);
        }
        fclose(of);
    }
}

void collect_data(cell **cells)
{
    int selection = ask_cell_num(1, 21, "\nWhat cell do you want to collect? (1-21): ");

    char cell_n[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_n, "%d", selection);

    //Concatenating strings together to form the filename
    char filename[] = {"./input_files/cells/info_cell_"};
    strcat(filename, cell_n);
    strcat(filename, ".txt");

    cells_read(filename, *cells); //see why pointer

    printf("\nDo you want to add another access point? [y/n]: ");
				char result = getchar();
    switch (result)
    {
    	case 'y': //you dont need to repeat the sys exit or break
    	case 'Y':
            collect_data(cells);

    	case 'n':
    	case 'N':
            system("clear");
    	break;

    	default:
    		printf("\nError: input was not valid, try again\n");
            system("clear");
    	break;
    }
}   
