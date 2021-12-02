/*
 * lab2_2_main.c
 */

#include "lab2_2.h"

int main() {
    // create a new hashtable with the capacity to hold 32 elements
    // this capacity is an arbitrary choice, it could be any value
    hashtable_t hashtable = hashtable_new(32);

    // initialize the element variable we use for doing operations on the
    // hashtable
    int key = -1;

    // loop indefinetly
    while (1) {
        printf("Insert a key (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &key);

        // if the element is -1, break out of the loop
        if (key == -1) {
            break;
        }

        // insert the key in the hash table
        hashtable_insert(&hashtable, key);

        // and then print the contents of the hash table
        printf("Contents of the hash table:\n");
        hashtable_print(&hashtable);
    }

    printf("Done\n");

    while (1) {
        printf("Search for a key (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &key);

        // if the element is -1, break out of the loop
        if (key == -1) {
            break;
        }

        // search for the key in the hash table
        int slot = hashtable_search(&hashtable, key);
        // if the slot is a positive integer it means we've found the key
        if (slot > -1) {
            printf("Search: found %d, slot %d\n", key, slot);
        } else {
            // otherwise, the key is missing
            printf("Search: key %d not found\n", key);
        }
    }

    printf("Done\n");

    while (1) {
        printf("Delete a key (or -1 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &key);

        // if the element is -1, break out of the loop
        if (key == -1) {
            break;
        }

        // delete the key from the hash table
        int slot = hashtable_delete(&hashtable, key);

        // if the slot is a positive integer it means we've found and deleted
        // the key
        if (slot > -1) {
            printf("Delete: deleted %d from slot %d\n", key, slot);
        } else {
            // otherwise, the key was missing
            printf("Delete: key %d not found\n", key);
        }

        // print the contents of the hash table
        printf("Contents of the hash table:\n");
        hashtable_print(&hashtable);
    }

    printf("Done\n");

    // deallocate the hash table
    hashtable_free(&hashtable);

    // return 0 to indicate success
    return 0;
}

