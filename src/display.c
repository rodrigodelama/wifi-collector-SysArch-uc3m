#include<stdio.h>
#include"../incl/cells.h"

// Display option meant to print data from the requested, or all cells onto the commandline

// TODO: create display individual Cells or the complete array
void display_cell()
{
    
   int num_cell_to_display = ask_cell_num(1, 21, " "); //registration of the cell to display
   
   for(int i = 0; i<CELL_LINE_SIZE; i++)
   {
      if(cell_storage[i].cell_X==num_cell_to_display)
      {
         printf("Cell %d:",cell_storage[i].cell_X, " %s", cell_storage[i].MAC_Address, " %s", cell_storage[i].ESSID, " %s", cell_storage[i].Mode, " %d", cell_storage[i].channel, "%s", cell_storage[i].encryption, " %s", cell_storage[i].quality, "%s", cell_storage[i].frequency, "%s\n", cell_storage[i].signal_lvl);
      }
   }

   printf("Do you want to add another access point? [y/N]: ");
      char result = getchar();
      

}   