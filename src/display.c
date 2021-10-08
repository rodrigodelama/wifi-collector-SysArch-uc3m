#include<stdio.h>
#include<string.h>
#include"../incl/cells.h"

// Display option meant to print data from the requested, or all cells onto the commandline

// TODO: create display individual Cells or the complete array
void display_ind_cell()
{
    
   int num_cell_to_display = ask_cell_num(1, 21, " "); //registration of the cell to display
   
   for(int i = 0; i<LINE_SIZE; i++)
   {
      if(cells[i].cell_n==num_cell_to_display)
      {
         printf("Cell %d:",cells[i].cell_n, " %s", cells[i].MAC_Address, " %s", cells[i].ESSID, " %s", cells[i].mode, " %d", cells[i].channel, "%s", cells[i].encryption, " %s", cells[i].quality, "%s", cells[i].frequency, "%s\n", cells[i].signal_lvl);
      }

      if(strlen(cells[i].cell_n)==0)
      break;
   }

   printf("Do you want to add another access point? [y/N]: ");
      char result = getchar();
      switch (result)
      {
      case 'y':
      case 'Y': 

         printf("\nIndicate the number of the cell for which you want to know its information (1 - 21):\n");
         display_cell();
         break;
      
      case 'n':
      case 'N':
       //action to make if chosen NO
         break;
      }

}   
/*
void display_all(){
    for(int i = 0; i<LINE_SIZE; i++)
   {
      printf("Cell %d:",cells[i].cell_n, " %s", cells[i].MAC_Address, " %s", cells[i].ESSID, " %s", cells[i].mode " %d", cells[i].channel, "%s", cells[i].encryption, " %s", cells[i].quality, "%s", cells[i].frequency, "%s\n", cells[i].signal_lvl);
  
      if(strlen(cells[i].cell_n)==0)
      break;
   
   }

}
*/