/*
 * lab1_1.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab1_1.h"

list_t list_new() {
    // create a new list
    list_t list;

    // assign the address of the first node as NULL because the list is empty
    // as of right now
    list.head = NULL;

    // return the list
    return list;
}

void list_delete(list_t * list, list_node_t * node) {
    // check that the pointer to the list is not null
    // dereferencing a null pointer is undefined behaviour
    if (list == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // check that the pointer to the node is not null
    // dereferencing a null pointer is undefined behaviour
    if (node == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if this is the first node (has no previous node), mark it as the head
    // node of the list
    if (node->prev == NULL) {
        list->head = node->next;
        // if the new head of the list is an actual node, remove the address
        // of it's previous node
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
    } else {
        // othwerise, assign the next node for the previous node as the next
        // node of the node that should be deleted
        node->prev->next = node->next;
    }
    // if this node has a next node, assign it's previous node as the previous
    // node of the node that should be deleted
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    // deallocate the node
    free(node);
}

void list_free(list_t * list) {
    // check that the pointer to the list is not null
    // dereferencing a null pointer is undefined behaviour
    if (list == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // get the first node in the list
    list_node_t * node = list->head;

    // while there are nodes in the list, deallocate them one by one
    while (node != NULL) {
        // save the next node
        list_node_t * next = node->next;
        // deallocate the current node
        free(node);
        // update the current node to be the next node
        node = next;
    }
}

void list_insert(list_t * list, int key) {
    // check that the pointer to the list is not null
    // dereferencing a null pointer is undefined behaviour
    if (list == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // allocate memory on the heap for a node in the list
    list_node_t * node = malloc(sizeof(list_node_t));
    // costruct the list node
    node->key = key;
    node->prev = NULL;
    node->next = NULL;

    // if there was no other node in the list, set this node as the first node
    if (list->head == NULL) {
        list->head = node;
        return;
    }

    // otherwise, append this node at the end of the list

    // iterate over all nodes until we reach the end of the list (a node that
    // has no other node after it)
    list_node_t * tip = list->head;
    while (tip->next != NULL) {
        tip = tip->next;
    }
    // append the new node at the end of the list
    tip->next = node;
    node->prev = tip;
}

void list_print(list_t * list) {
    // check that the pointer to the list is not null
    // dereferencing a null pointer is undefined behaviour
    if (list == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // iterate over all nodes
    list_node_t * node = list->head;
    while (node != NULL) {
        // print the key of the node and then a white space
        printf("Node %p: %d, prev(%p), next(%p)\n", node, node->key, node->prev, node->next);
        // assign the current node as the next node
        node = node->next;
    };

    // print a new line (for aesthetic reasons)
}

list_node_t * list_search(list_t * list, int key) {
    // check that the pointer to the list is not null
    // dereferencing a null pointer is undefined behaviour
    if (list == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // iterate over all nodes
    list_node_t * node = list->head;
    while (node != NULL) {
        // if the key of the current node matches the key that we are searching
        // for, stop searching
        if (node->key == key) {
            break;
        }
        // othwerise, set the current node as the next node
        node = node->next;
    }

    // return the node
    return node;
}

int main() {
    // create a new list
    list_t list = list_new();

    // print the menu
    printf("0 -> exit\n");
    printf("1 -> insert\n");
    printf("2 -> search\n");
    printf("3 -> delete\n");
    printf("4 -> print\n");

    // set the default choice to -1 - this is an unused value
    int choice = -1;

    // while the choice is not 0, loop through the menu
    while (choice != 0) {
        printf("Your choice: ");
        // read the desired operation
        scanf("%d", &choice);

        // declare required variables
        int key;
        list_node_t * node;

        // match on the chosen operation
        switch (choice) {
            // insert
            case 1:
                printf("Insert - enter a value: ");
                // read the desired value
                scanf("%d", &key);
                // insert the value into the list
                list_insert(&list, key);
                break;
            // search
            case 2:
                printf("Search - enter a value: ");
                // read the desired value
                scanf("%d", &key);
                // search for the value
                node = list_search(&list, key);
                // if the key exists, print it
                if (node != NULL) {
                    printf("Search - node %p (%d)\n", node, key);
                } else {
                    // otherwise, print a failure message
                    printf("Search - key not found\n");
                }
                break;
            // delete
            case 3:
                printf("Delete - enter a value: ");
                // read the desired value
                scanf("%d", &key);
                // search for the value
                node = list_search(&list, key);
                // if the key exists, delete it and print a success message
                if (node != NULL) {
                    list_delete(&list, node);
                    printf("Delete - ok\n");
                } else {
                    // otherwise, print a failure message
                    printf("Delete - key not found\n");
                }
                break;
            // print
            case 4:
                printf("Print\n");
                // print the linked list
                list_print(&list);
                break;
            // exit
            case 0:
                // say goodbye
                printf("Goodbye\n");
                break;
            // default - other values not handled specifically handled by this
            // switch statement
            default:
                // print a message indicating failure to understand the desired
                // command
                printf("Unknown choice: %d\n", choice);
                break;
        }
    }

    // deallocate the list
    list_free(&list);

    // return ok
    return 0;
}
