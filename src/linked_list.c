//Gorka Bernad - 100451457@alumnos.uc3m.es
//Rodrigo De Lama - 100451775@alumnos.uc3m.es

//All credit to the respective owner - Boni Garcia (@bonigarcia on GitHub)
//Linked list file, based on Boni Garcia's "linked_list.c"
//https://github.com/bonigarcia/c-examples/blob/master/dynamic_mem/linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../incl/cells.h"
#include "../incl/dependencies.h"

//Node *deleted = NULL;
//Node *prev = NULL;

// Node definition in cells.h 

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

//Delete list (free memory)
void clear_list(Node **head) {
    Node *current = *head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void delete_net()
{
   extern Node *head;

   printf("\nIndicate the ESSID (use \"\"): ");
		char net[MAX_STRING_SIZE];
	   scanf("%s", net); //net is the name of the ESSID we want to find in the list

   delete_node(&head, net);
}

//Delete node by ESSID[]
//use strcmp() to compare char arrays here
// 0 means match, != 0 means not same
void delete_node(Node **head, char ESSID[])
{
    int pos_count = 0;

    Node *tmp = *head, *prev;
    //ESSID
    //deletes first element
    if (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) == 0)
    {
        *head = tmp->next;
        free(tmp);

        printf("\nFound ESSID %s at position %d, it's now deleted\n\n", ESSID, 0);
        sleep(3);

        return;
    }

    for (tmp = *head; tmp->next != NULL; tmp = tmp->next)
    {
        while (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) != 0)
        {
            pos_count++;

            prev = tmp;
            //append(&deleted, tmp);
            tmp = tmp->next;
            
            if (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) == 0)
            {
                printf("\nFound ESSID %s at position %d, it's now deleted\n\n", ESSID, pos_count);
                sleep(3);
                prev->next = tmp->next;
                free(tmp);
            }
        }
    }
    
    /**
    //deletes any other element
    while (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) != 0)
    {
        pos_count++;

        prev = tmp;
        //append(&deleted, tmp);
        //tmp = tmp->next;
        
        if (tmp != NULL && strcmp(tmp->data.ESSID, ESSID) == 0)
        {
            printf("\nFound ESSID %s at position %d, it's now deleted\n\n", ESSID, pos_count);
            sleep(3);
            system("clear");
        }
    }
    */

    if (tmp == NULL)
    {
        printf("No such ESSID found\n\nDo you want to delete another ESSID? [y/n]: ");
        getchar(); //to grab the enter key
        char choice = getchar();
        switch (choice)
        {
            case 'Y':
            case 'y':
                delete_net();
            break;

            case 'N':
            case 'n':
                system("clear");
            break;

            default:
                printf("\nError: input was not valid, try again\n");
                sleep(4);
                system("clear");
            break;
        }
        return;
    }


}
