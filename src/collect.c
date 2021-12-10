//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../incl/cells.h"
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

void cells_read(char filename[])
{
    extern Node *head;
    cell aux;
    
	FILE *of;
	of = fopen(filename,"r");

    if (of == NULL)
    {
      	fprintf(stderr, "The File: %s was not found.\n", filename);
	}
    else
    {
        int exit_cond = 1;
        do
        {
            if (fscanf(of, "Cell %d\nAddress: %s\nESSID:%[^\n]\nMode:%s\nChannel:%d\nEncryption key:%s\nQuality=%s\nFrequency:%s GHz\nSignal level=%s dBm\n",
                        &aux.cell_n, aux.MAC_Address, aux.ESSID, aux.mode, &aux.channel, aux.encryption, aux.quality, aux.frequency, aux.signal_lvl) == EOF)
            {
                exit_cond = 0;
            }

            //avoids double reading the last cell entry
            if (exit_cond != 0)
            {
                printf("\nData read from info_cell_%d.txt (added to position %d of the list)", aux.cell_n, num_cell_ND);
                printf("\nCell %d: %s %s %s %d %s %s %s000 %s\n", 
                    aux.cell_n, aux.MAC_Address,
                    aux.ESSID, aux.mode,
                    aux.channel, aux.encryption,
                    aux.quality, aux.frequency,
                    aux.signal_lvl);

                Node *new_node = create_node(aux);
                append(&head, new_node);
            }
        } while (exit_cond == 1);
        
        fclose(of);
    }
}

void collect_data()
{
    int selection = ask_num(1, 21, "\nWhat cell do you want to collect? (1-21): ");

    char cell_n[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_n, "%d", selection);

    //Concatenating strings together to form the filename
    char filename[] = {"./input_files/cells/info_cell_"};
    strcat(filename, cell_n);
    strcat(filename, ".txt");

    cells_read(filename);

    printf("\nDo you want to add another access point? [y/n]: ");
				char result = getchar();
    switch (result)
    {
    	case 'y': //you dont need to repeat the sys exit or break
    	case 'Y':
            collect_data();
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
}   
