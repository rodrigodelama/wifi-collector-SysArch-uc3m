/*********************************************************************************************************************
 *
 * FILE NAME:   commands.c
 *
 * AUTHOR:    	Maria Blanca Ibanez
 *
 * PURPOSE:   	Functions that handle the options for the user:
 *			* read the books from a preconfigured fileinto a "data base"
 *			* display all the books stored into the "data base"
 *			* search a book by its title 
 * ASSUMPTIONS, CONSTRAINS, RESTRICTIONS: 
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
#include "../incl/books.h"

extern int bindex;

// read the books from a file 
// to store the information read requires the function: insert_new_book() from books.{h,c}
void books_read(char file_name[SIZE]){
	FILE *fd;

	int type;
        char isbn[15];
        char last_name[SIZE];
        char first_name[SIZE];
        char title[SIZE];
        float price;


	fd = fopen(file_name,"r");

    	if (fd == NULL) {
      		fprintf(stderr, "The File: %s was not found.\n", file_name);
    	}

    	while( fscanf(fd, "%d %s %s %s %s %f\n", &type, &isbn, &last_name, &first_name, &title, &price) != EOF){
		insert_new_book(type, isbn, last_name, first_name, title, price);
    	}
  
    	fclose(fd);
}

// prints the information of all the books in the bookstore
// (it uses display()'s function from from books.c)
void books_display(){
	for (int i = 0; i < bindex; i++){
		display(i);
	}
}

// ask the user for the title of a book
// to search in the database (it uses find_title()'s function from from books.c)
// print the information about the book (it uses display()'s function from from books.c)
void books_search(){
	// HOMEWORK
	printf("Not implemented yet\n");
}

