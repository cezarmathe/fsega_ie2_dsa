/*
 * lab2_1_main.c
 */

#include <stdio.h>

#include "lab2_1.h"

int main() {

    hashtable_t hashtable = hashtable_new(32);

    int element = -1;

    // loop indefinetly
    while (1) {
        printf("Append a number (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &element);

        // if the element is 0, break out of the loop
        if (element == -1) {
            break;
        }

        // add the element in the hash table
        hashtable_insert(&hashtable, element);

        printf("Contents of the hash table:\n");
        // and then print the contents of the queue
        hashtable_print(&hashtable);
    }

    printf("Done\n");

    while (1) {
        printf("Search for a key (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &element);

        // if the element is -1, break out of the loop
        if (element == -1) {
            break;
        }

        // add the element in the hash table
        int slot = hashtable_search(&hashtable, element);
        if (slot > -1) {
            printf("Found %d, slot %d\n", element, slot);
        } else {
            printf("Not found %d\n", element);
        }
    }

    while (1) {
        printf("Delete a key (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &element);

        // if the element is -1, break out of the loop
        if (element == -1) {
            break;
        }

        // add the element in the hash table
        int slot = hashtable_delete(&hashtable, element);

        if (slot > -1) {
            printf("Deleted %d from slot %d\n", element, slot);
        } else {
            printf("Not found %d\n", element);
        }

        printf("Contents of the hash table:\n");
        // and then print the contents of the queue
        hashtable_print(&hashtable);
    }

    hashtable_free(&hashtable);

    return 0;
}
