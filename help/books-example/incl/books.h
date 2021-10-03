/*********************************************************************************************************************
 *
 * FILE NAME:   books.h
 *
 * AUTHOR:    	Maria Blanca Ibanez
 *
 * PURPOSE:   	Data structures that represents the database
 *			* structure that represents a book: "struct books_st"
 *			* struct books_st considers:
 *				* two different ISBN formats: "struct isbn_10_st" and "struct isbn_13_st"
 *				* Authors'name stored as a struct that specifies last and first name
 *				* Books' title
 *				* Books' price
 *			* data base: array of structs: "books"
 *
 * ASSUMPTIONS, CONSTRAINS, RESTRICTIONS: 	
 *			* There is a maximum amount of books: MAX_AMOUNT_BOOKS
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

#ifndef _BOOKS_H
#define _BOOKS_H

#define SIZE 80
#define MAX_AMOUNT_BOOKS 120

extern int bindex;

enum isbn_type {TEN_DIGITS, THIRTEEN_DIGITS};

struct author_st{
 char last_name[SIZE];
 char first_name[SIZE];
};

struct isbn_10_st{
   char group[3];
   char publisher[5];
   char title[4];
   int  check_digit;
};

struct isbn_13_st{
   char isbn_info[4];
   char language[2];
   char publisher[7];
   char title_edition[3];
   int  check_digit;
};

struct books_st{
  enum isbn_type type;
  union {
	struct isbn_10_st isbn_10;
	struct isbn_13_st isbn_13;
  }isbn;
  struct author_st author;
  char title[SIZE];
  float price;
};

struct books_st books[MAX_AMOUNT_BOOKS];

void insert_new_book(int type, char isbn[15], char last_name[SIZE], char first_name[SIZE], char title[SIZE], float price);
void display(int n);
int  find_title(char title[SIZE]);


#endif
