//Rodrigo De Lama - 100451775@alumnos.uc3m.es
//Gorka Bernad - 100451457@alumnos.uc3m.es

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

//Declaration of our libraries
#include "../incl/cells.h"
#include "../incl/sizes.h"
#include "../incl/bool.h"

int ask_cell_num(int min, int max, char message[])
{
    int option; //another idea is to use getchar()
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

// read cells from the file 
// to store the information read requires the function: insert_new_book() from books.{h,c}
void cells_read(char filename[])
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

    if (of == NULL) {
      	fprintf(stderr, "The File: %s was not found.\n", filename);
	} else {

        //    char format[9][MAX_STRING_SIZE] = { "%*s %s:", "%*s %s", "%*[^:]: %s", "%*[^:]: %s", "%*[^:]: %s",
        //                                        "%*[^:]: %s", "%*[^=]= %s", "%*[^:]: %s000", "%*[^=]= %s" };
        // "%*s %d %*[^:]: %s %*[^:]: %s %*[^:]: %s %*[^:]: %d%*[^:]:%s%*[^=]=%s%*[^:]:%s%*[^=]=%s"
        
//TODO: BIG ISSUE W fscanf()
        while (fscanf(of, "Cell %d\nAddress: %s\nESSID:%s\nMode:%s\nChannel:%d\nEncryption key:%s\nQuality=%s\nFrequency:%s GHz\nSignal level=%s dBm\n",
                      &cell_n, MAC_Address, ESSID, mode, &channel, encryption, quality, frequency, signal_lvl) != EOF)
        {
	    insert_new_cell(cell_n, MAC_Address, ESSID, mode, channel, encryption, quality, frequency, signal_lvl);
        }

/*                
        int i = 1;

        while (i < 4)
        {
        fscanf(of, "%*s %d\n %*s %s\n %*[^:]: %s\n %*[^:]: %s\n %*[^:]: %d\n %*[^:]: %s\n %*[^=]= %s\n %*[^:]: %s\n %*[^=]= %s %* \n",
                      &cell_n, MAC_Address, ESSID, mode, &channel, encryption, quality, frequency, signal_lvl);
                      
	    insert_new_cell(cell_n, MAC_Address, ESSID, mode, channel, encryption, quality, frequency, signal_lvl);
        i++;
        }
*/  
        fclose(of);
    }
}

void collect_data()
{
    int selection = ask_cell_num(1, 21, "\nWhat cell do you want to collect? (1-21): ");

    char cell_n[MAX_STRING_SIZE];

    //string to char
    sprintf(cell_n, "%d", selection);

    //Concatenating strings together to form the filename
    char filename[] = {"./input_files/cells/info_cell_"};
    strcat(filename, cell_n);
    strcat(filename, ".txt");

    printf("%s\n", filename);
    sleep(1);

    cells_read(filename);

    //create an array to know if cells were already searched


    printf("\nDo you want to add another access point? [y/n]: ");
				char result = getchar();
    switch (result)
    {
    	case 'y': //you dont need to repeat the sys exit or break
    	case 'Y':
            collect_data();

    	case 'n':
    	case 'N':
            system("clear");
    		break;

    	default:
    		printf("\nError: input was not valid, try again\n");
    		break;
    }  
}   


//possible switch for thr integration of the data
//bool get


//old - IGNORE
/*
int option = ask_cell_num(1,21, msg)
for(int I =0; i<Cell_line_SIZE; i++){
    if(cell_st[i].cell_n == option;)
    display(cell_st[i])
}
*/
