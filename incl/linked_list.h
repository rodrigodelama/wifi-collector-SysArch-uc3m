//Gorka Bernad - 100451457@alumnos.uc3m.es
//Rodrigo De Lama - 100451775@alumnos.uc3m.es

//Linked List
//All credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)

#include "../incl/dependencies.h"
#include "../incl/cells.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Node definition
/**
typedef struct Node {
    int cell_n;
    char MAC_Address[LINE_SIZE];
    char ESSID[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char encryption[LINE_SIZE];
    char quality[LINE_SIZE];
    char frequency[LINE_SIZE];
    char signal_lvl[LINE_SIZE];
    struct Node *next;
} Node;
 */

//Create new node (using data as input)
Node *create_node(int cell_n, char MAC_Address[], char ESSID[], char mode[], int channel,
                  char encryption[], char quality[], char frequency[], char signal_lvl[]);
//Insert Node at the beginning
void push(Node **head_ref, Node *new_node);
//Insert Node at the end
void append(Node **head_ref, Node *new_node);
//Insert Node after a giving position
void insert_after(Node *prev_node, Node *new_node);
//Print list content on the standard output
void print_list(Node *head);
//Delete list (free memory)
void clear_list(Node **head_ref);
//Make a copy of a list
Node* clone_list(Node *head);
//Swap nodes
void swap(Node *a, Node *b);
//Delete node by value
void delete_node(Node **head_ref, char ESSID[] /*ESSID is our key*/);

#endif
