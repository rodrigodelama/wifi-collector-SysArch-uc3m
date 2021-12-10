/**
 * Gorka Bernad - 100451457@alumnos.uc3m.es
 * Rodrigo De Lama - 100451775@alumnos.uc3m.es
 * 
 * cells.h:
 * - declares our dynamic array of structures of type cell_st
 * - declares the global int value position, to be used to track our position when traversing the array
 * - declares methods to: insert a new cell, display a specific individual cell and< to display all recorded cell
 * 
 * All Linked Lists credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)
 */

#ifndef CELLS_H
#define CELLS_H

#include "../incl/dependencies.h"
#include "../incl/linked_list.h"

typedef struct cell_st
{
    int cell_n;
    char MAC_Address[LINE_SIZE];
    char ESSID[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char encryption[LINE_SIZE];
    char quality[LINE_SIZE];
    char frequency[LINE_SIZE];
    char signal_lvl[LINE_SIZE];

} cell;

int num_cell_ND;

void insert_new_cell(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                     char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                     char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE]);
void display_ind_cell();
void display_all();
int ask_num(int min, int max, char message[]);


//NODE stuff
typedef struct Node {
    cell data;
    struct Node *next;
} Node;

//Create new node (using data as input)
Node *create_node(cell data);
//Insert Node at the end
void append(Node **head_ref, Node *new_node);
//Delete a node
void delete_node(Node **head_ref, char ESSID[]); //ESSID is our key
//Delete list (free memory)
void clear_list(Node **head_ref);

#endif
