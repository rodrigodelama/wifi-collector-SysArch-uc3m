/*********************************************************************************************************************
 *
 * FILE NAME:   books.c
 *
 * AUTHOR:    	Maria Blanca Ibanez
 *
 * PURPOSE:   	Functions that handle the database
 *			* insert_new_book()
 *			* display the information of a book stored into the "data base"
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
#include <string.h>

#include "../incl/books.h"

int bindex = 0;

// insert a book into the data base: "books' array"
void insert_new_book(int type, char isbn[15], char last_name[SIZE], char first_name[SIZE], char title[SIZE], float price){

	if(bindex < MAX_AMOUNT_BOOKS){

	switch (type) {
		case 10: 
			books[bindex].type = TEN_DIGITS; 

			books[bindex].isbn.isbn_10.group[0] = isbn[0];
			books[bindex].isbn.isbn_10.group[1] = isbn[1];
			books[bindex].isbn.isbn_10.group[2] = '\0';

			books[bindex].isbn.isbn_10.publisher[0] = isbn[2];
			books[bindex].isbn.isbn_10.publisher[1] = isbn[3];
			books[bindex].isbn.isbn_10.publisher[2] = isbn[4];
			books[bindex].isbn.isbn_10.publisher[3] = isbn[5];
			books[bindex].isbn.isbn_10.publisher[4] = '\0';

			books[bindex].isbn.isbn_10.title[0] = isbn[6];
			books[bindex].isbn.isbn_10.title[1] = isbn[7];
			books[bindex].isbn.isbn_10.title[2] = isbn[8];
			books[bindex].isbn.isbn_10.title[3] = '\0';

			books[bindex].isbn.isbn_10.check_digit = isbn[9] - '0';
			break;
		case 13: 
			books[bindex].type = THIRTEEN_DIGITS; 

			books[bindex].isbn.isbn_13.isbn_info[0] = isbn[0];
			books[bindex].isbn.isbn_13.isbn_info[1] = isbn[1];
			books[bindex].isbn.isbn_13.isbn_info[2] = isbn[2];
			books[bindex].isbn.isbn_13.isbn_info[3] = '\0';

			books[bindex].isbn.isbn_13.language[0] = isbn[3];
			books[bindex].isbn.isbn_13.language[1] = '\0';

			books[bindex].isbn.isbn_13.publisher[0] = isbn[4];
			books[bindex].isbn.isbn_13.publisher[1] = isbn[5];
			books[bindex].isbn.isbn_13.publisher[2] = isbn[6];
			books[bindex].isbn.isbn_13.publisher[3] = isbn[7];
			books[bindex].isbn.isbn_13.publisher[4] = isbn[8];
			books[bindex].isbn.isbn_13.publisher[5] = isbn[9];
			books[bindex].isbn.isbn_13.publisher[6] = '\0';

			books[bindex].isbn.isbn_13.title_edition[0] = isbn[10];
			books[bindex].isbn.isbn_13.title_edition[1] = isbn[11];
			books[bindex].isbn.isbn_13.title_edition[2] = '\0';

			books[bindex].isbn.isbn_13.check_digit = isbn[12] - '0';
			break;
		default: 
			printf("input error, isbn type must be 10 or 13");
	}

	strcpy(books[bindex].author.last_name, last_name);
	strcpy(books[bindex].author.first_name, first_name);
	strcpy(books[bindex].title, title);
	books[bindex].price = price;

	bindex++;

	} else {
		printf("Books overflow\n");
	}

}

// print the information of a book
void display(int i){
	if(books[i].type == TEN_DIGITS){ 
		printf("ISBN10: %s-%s-%s-%d\n", 
		books[i].isbn.isbn_10.group, 
		books[i].isbn.isbn_10.publisher, 
		books[i].isbn.isbn_10.title, 
		books[i].isbn.isbn_10.check_digit);
   	} else{
		printf("ISBN13: %s-%s-%s-%s-%d\n", 
		books[i].isbn.isbn_13.isbn_info, 
		books[i].isbn.isbn_13.language, 
		books[i].isbn.isbn_13.publisher, 
		books[i].isbn.isbn_13.title_edition,
		books[i].isbn.isbn_13.check_digit);
	}
	printf("Author: %s, %s\n", books[i].author.last_name, books[i].author.first_name);
	printf("Title: %s\n", books[i].title);
	printf("Price: %3.2f\n\n", books[i].price);
}

// search a book with a specific title
// returns -1 if it is not found
// return its position in books' array otherwise
int find_title(char title[SIZE]){
	// HOMEWORK
        printf("Not implemented yet\n");
	return 0;
}







