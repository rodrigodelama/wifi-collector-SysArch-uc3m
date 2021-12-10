//Gorka Bernad - 100451457@alumnos.uc3m.es
//Rodrigo De Lama - 100451775@alumnos.uc3m.es

//All credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)
//Linked list file, based on Boni Garcia's "linked_list.c"
//https://github.com/bonigarcia/c-examples/blob/master/dynamic_mem/linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/linked_list.h"
#include "../incl/dependencies.h"

// Node definition in .h 

//Create new node
Node *create_node_ll(int cell_n, char MAC_Address[LINE_SIZE], char ESSID[LINE_SIZE], 
                  char mode[LINE_SIZE], int channel, char encryption[LINE_SIZE],
                  char quality[LINE_SIZE], char frequency[LINE_SIZE], char signal_lvl[LINE_SIZE])
{   
    Node *node = (Node*) malloc(sizeof(Node));
    node->cell_n = cell_n;
    strcpy(node->MAC_Address, MAC_Address);
    strcpy(node->ESSID, ESSID);
    strcpy(node->mode, mode);
    node->channel = channel;
    strcpy(node->encryption, encryption);
    strcpy(node->quality, quality);
    strcpy(node->frequency, frequency);
    strcpy(node->signal_lvl, signal_lvl);
    node->next = NULL;

    return node;
}

//Insert Node at the beginning
void push(Node **head_ref, Node *new_node)
{
    new_node->next = *head_ref;
    *head_ref = new_node;
}

//Insert Node at the end
void append(Node **head_ref, Node *new_node)
{
    Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

//Insert Node after a giving position
void insert_after(Node *prev_node, Node *new_node)
{
    if (prev_node == NULL)
    {
        printf("The previous node cannot be NULL\n");
        return;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//Print list content on the standard output
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf(" %d", head->cell_n);
        printf(" %s", head->MAC_Address);
        printf(" %s", head->ESSID);
        printf(" %s", head->mode);
        printf(" %d", head->channel);
        printf(" %s", head->encryption);
        printf(" %s", head->quality);
        printf(" %s", head->frequency);
        printf(" %s", head->signal_lvl);
        head = head->next;
    }
    printf("\n");
}

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

//Make a copy of a list
Node* clone_list(Node *head)
{
    Node *current = head;
    Node *new_list = NULL;
    Node *tail = NULL;

    while (current != NULL)
    {
        Node *new_node = (Node*) malloc(sizeof(Node));
        memcpy(new_node, current, sizeof(Node));

        if (new_list == NULL)
        {
            push(&new_list, new_node);
            tail = new_list;
        } else {
            push(&(tail->next), new_node);
            tail = tail->next;
        }
        current = current->next;
    }

    return new_list;
}

//Swap nodes
void swap(Node *a, Node *b)
{
    Node tmp;
    //cell_n
    tmp.cell_n = a->cell_n;
    a->cell_n = b->cell_n;
    b->cell_n = tmp.cell_n;
    //MAC_Address
    strcpy(tmp.MAC_Address, a->MAC_Address);
    strcpy(a->MAC_Address, b->MAC_Address);
    strcpy(b->MAC_Address, tmp.MAC_Address);
    //ESSID
    strcpy(tmp.ESSID, a->ESSID);
    strcpy(a->ESSID, b->ESSID);
    strcpy(b->ESSID, tmp.ESSID);
    //mode
    strcpy(tmp.mode, a->mode);
    strcpy(a->mode, b->mode);
    strcpy(b->mode, tmp.mode);
    //channel
    tmp.channel = a->channel;
    a->channel = b->channel;
    b->channel = tmp.channel;
    //encryption
    strcpy(tmp.encryption, a->encryption);
    strcpy(a->encryption, b->encryption);
    strcpy(b->encryption, tmp.encryption);
    //quality
    strcpy(tmp.quality, a->quality);
    strcpy(a->quality, b->quality);
    strcpy(b->quality, tmp.quality);
    //frequency
    strcpy(tmp.frequency, a->frequency);
    strcpy(a->frequency, b->frequency);
    strcpy(b->frequency, tmp.frequency);
    //signal_lvl
    strcpy(tmp.signal_lvl, a->signal_lvl);
    strcpy(a->signal_lvl, b->signal_lvl);
    strcpy(b->signal_lvl, tmp.signal_lvl);
}

//Delete node by value

//USE char ESSID[] as our key
//*head_ref is the pointer to our head node
//use strcmp() to compare char arrays here

void delete_node(Node **head_ref, char ESSID[] /*ESSID is our key*/)
{
    Node *tmp = *head_ref, *prev;
    //ESSID
    if (tmp != NULL && strcmp(tmp->ESSID, ESSID) == 1)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && strcmp(tmp->ESSID, ESSID) == 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //
    if (tmp == NULL)
    {
        return;
    }

    prev->next = tmp->next;

    free(tmp);
}