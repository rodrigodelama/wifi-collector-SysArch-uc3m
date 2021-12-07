//Gorka Bernad - 100451457@alumnos.uc3m.es
//Rodrigo De Lama - 100451775@alumnos.uc3m.es

//All credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)
//Linked list file, based on Boni Garcia's "linked_list.c"
//https://github.com/bonigarcia/c-examples/blob/master/dynamic_mem/linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/linked_list.h"

// Node definition in .h 

//Create new node
Node* create_node(int cell_n, char MAC_Address[], char ESSID[], char mode[], int channel,
                  char encryption[], char quality[], char frequency[], char signal_lvl[])
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->cell_n = cell_n;
    node->MAC_Address = MAC_Address;
    node->ESSID = ESSID;
    node->mode = mode;
    node->channel = channel;
    node->encryption = encryption;
    node->quality = quality;
    node->frequency = frequency;
    node->signal_lvl = signal_lvl;
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
        printf(" %d", head->MAC_Address);
        printf(" %d", head->ESSID);
        printf(" %d", head->mode);
        printf(" %d", head->channel);
        printf(" %d", head->encryption);
        printf(" %d", head->quality);
        printf(" %d", head->frequency);
        printf(" %d", head->signal_lvl);
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
    tmp.MAC_Address = a->MAC_Address;
    a->MAC_Address = b->MAC_Address;
    b->MAC_Address = tmp.MAC_Address;
    //ESSID
    tmp.ESSID = a->ESSID;
    a->ESSID = b->ESSID;
    b->ESSID = tmp.ESSID;
    //mode
    tmp.mode = a->mode;
    a->mode = b->mode;
    b->mode = tmp.mode;
    //channel
    tmp.channel = a->channel;
    a->channel = b->channel;
    b->channel = tmp.channel;
    //encryption
    tmp.encryption = a->encryption;
    a->encryption = b->encryption;
    b->encryption = tmp.encryption;
    //quality
    tmp.quality = a->quality;
    a->quality = b->quality;
    b->quality = tmp.quality;
    //frequency
    tmp.frequency = a->frequency;
    a->frequency = b->frequency;
    b->frequency = tmp.frequency;
    //signal_lvl
    tmp.signal_lvl = a->signal_lvl;
    a->signal_lvl = b->signal_lvl;
    b->signal_lvl = tmp.signal_lvl;
}

//Delete node by value

//USE char ESSID[] as our key
//*head_ref is the pointer to our head node
//use strcmp() to compare char arrays here

void delete_node(Node **head_ref, int key, char ESSID[] /*ESSID is our key*/)
{
    Node *tmp = *head_ref, *prev;

    //cell_n
    if (tmp != NULL && tmp->cell_n == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->cell_n != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //MAC_Address
    if (tmp != NULL && tmp->MAC_Address == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->MAC_Address != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //ESSID
    if (tmp != NULL && tmp->ESSID == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->ESSID != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //mode
    if (tmp != NULL && tmp->mode == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->mode != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //channel
    if (tmp != NULL && tmp->channel == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->channel != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //encryption
    if (tmp != NULL && tmp->encryption == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->encryption != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //quality
    if (tmp != NULL && tmp->quality == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->quality != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //frequency
    if (tmp != NULL && tmp->frequency == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->frequency != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    //signal_lvl
    if (tmp != NULL && tmp->signal_lvl == key)
    {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->signal_lvl != key)
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
