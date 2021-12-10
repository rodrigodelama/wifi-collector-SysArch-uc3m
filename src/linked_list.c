//Gorka Bernad - 100451457@alumnos.uc3m.es
//Rodrigo De Lama - 100451775@alumnos.uc3m.es

//All credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)
//Linked list file, based on Boni Garcia's "linked_list.c"
//https://github.com/bonigarcia/c-examples/blob/master/dynamic_mem/linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/cells.h"
#include "../incl/dependencies.h"

// Node definition in .h 

//Create new node
Node *create_node(cell data)
{   
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

//Insert Node at the end of the Linked List
void append(Node **head, Node *new_node)
{
    Node *last = *head;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

/**
 * @brief 
 * 
 * @param head 
//Print list content on the standard output
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf(" %d", data.cell_n);
        printf(" %s", data.MAC_Address);
        printf(" %s", data.ESSID);
        printf(" %s", data.mode);
        printf(" %d", data.channel);
        printf(" %s", data.encryption);
        printf(" %s", data.quality);
        printf(" %s", data.frequency);
        printf(" %s", data.signal_lvl);
        head = head->next;
    }
    printf("\n");
}
 */


//Delete list (free memory)
void clear_list(Node **head_ref) {
    Node *current = *head_ref;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

//Delete node by value

//USE char ESSID[] as our key
//*head_ref is the pointer to our head node
//use strcmp() to compare char arrays here

void delete_node(Node **head_ref, char ESSID[] /*ESSID is our key*/)
{
    Node *tmp = *head_ref, *prev;
    //ESSID
    if (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) == 1)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) == 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }

    prev->next = tmp->next;

    free(tmp);
}