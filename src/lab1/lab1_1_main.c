/*
 * lab1_1_main.c
 */

#include <stdio.h>

#include "lab1_1.h"

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
