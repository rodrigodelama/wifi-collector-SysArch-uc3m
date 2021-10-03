/*********************************************************************************************************************
 *
 * FILE NAME: books.c
 *
 * AUTHOR:    	Maria Blanca Ibanez
 *
 * PURPOSE:   	Manage informacion about books in a bookstore.
 * 		The program interacts with a user through a menu implemented in the main().
 *		Options for the user:
 *			* read the books from a preconfigured file: "info_books.txt" and stored into a "data base"
 *			* display all the books stored into the "data base"
 *			* search a book by its title
 *
 * ASSUMPTIONS, CONSTRAINS, RESTRICTIONS:
 *		Menu will work as an infinite loop 
 *
 * Copyright   [Copyright (c) 2021 Carlos III University of Madrid
 * All rights reserved.
 *
 * Permission is hereby granted, without written agreement and without license
 * or royalty fees, to use, copy, modify, and distribute this software and its
 * documentation for any purpose, provided that the above copyright notice and
 * the following two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE CARLOS III UNIVERSITY OF MADRID BE LIABLE TO ANY PARTY 
 * FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING 
 * OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE CARLOS III
 * UNIVERSITY OF MADRID HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE CARLOS III UNIVERSITY OF MADRID SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN
 * "AS IS" BASIS, AND CARLOS III UNIVERSITY OF MADRID HAS NO OBLIGATION TO 
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.]
 *
 *********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../incl/books.h"
#include "../incl/commands.h"

void print_menu();
int  ask_for_number(int min, int max, char message[]);

int main(int argc, char *argv[]){

  do
    {
      print_menu();
 
      switch (ask_for_number(1, 3, "\nPrint your Option: ")) {
        case 1:
	  books_read("./input_files/info_books.txt");
          break;

        case 2:
	  books_display();
          break;

        case 3:
          books_search();
          break;

        default:
          printf("error, try again");
      }

  } while(1);

   return 0;
}

// Show the user the options to manage the "data base"
void print_menu(){
  printf("[2021] Books in the Bookstore\n");
  printf("  [ 1] books_read \n");
  printf("  [ 2] books_display\n");
  printf("  [ 3] books_search\n\n");
}

// Receive the number that represents the chosen option
int ask_for_number(int min, int max, char message[]){
    int option;
    char optionchar[SIZE];

    printf("%s", message);

    do{
        scanf("%s", optionchar);
        option = atoi(optionchar);
        if ( option < min || option > max ) { printf("Please introduce a number between %d-%d\n", min, max); }
      }while( option < min || option > max );

    return option;
}

