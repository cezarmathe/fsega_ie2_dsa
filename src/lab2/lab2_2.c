/*
 * lab2_2.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab1_1.h"
#include "lab2_2.h"

hashtable_t hashtable_new(int cap) {
    // allocate memory for the inner array of the hashtable
    list_t * inner = malloc(cap * sizeof(list_t));

    // initialize all table slots
    // this hashtable supports storing only positive integers
    for (int i = 0; i < cap; i++) {
        // create a new list in the slot
        inner[i] = list_new();
    };

    // create the hashtable struct
    hashtable_t hashtable;
    hashtable.inner = inner;
    hashtable.cap = cap;

    // return the hashtable
    return hashtable;
}

int hashtable_hash(hashtable_t * hashtable, int key) {
    // the hash is computed by getting the remainder of the division of the key
    // by the hashtable capacity
    return key % hashtable->cap;
}

int hashtable_insert(hashtable_t * hashtable, int key) {
    // get the hash of the key
    // this tells us where the key should be inserted
    int slot = hashtable_hash(hashtable, key);

    // insert the key in the list at the slot indicated by 'hash'
    list_insert(&hashtable->inner[slot], key);

    // return the slot
    return slot;
}

int hashtable_search(hashtable_t * hashtable, int key) {
    // get the hash of the key
    // this tells us what list should we search in
    int slot = hashtable_hash(hashtable, key);

    // search the list for the specified key
    // if no node was found, return -1 (indicating failure)
    if (list_search(&hashtable->inner[slot], key) == NULL) {
        return -1;
    }

    // return the slot where the key can be found
    return slot;
}

int hashtable_delete(hashtable_t * hashtable, int key) {
    // get the hash of the key
    // this tells us what list should we search in
    int hash = hashtable_hash(hashtable, key);

    // search the list for the specified key
    // if no node was found, return -1 (indicating failure)
    list_node_t * node = list_search(&hashtable->inner[hash], key);
    if (node == NULL) {
        return -1;
    }

    // delete the node in the list that contains this key
    list_delete(&hashtable->inner[hash], node);

    // return the slot
    return hash;
}

void hashtable_print(hashtable_t * hashtable) {
    // iterate over each slot in the table
    for (int i = 0; i < hashtable->cap; i++) {
        // print the slot number
        printf("   slot %d\n", i);
        // print the list
        list_print(&hashtable->inner[i]);
    }
}

void hashtable_free(hashtable_t * hashtable) {
    // deallocate each list from the inner array
    for (int i = 0; i < hashtable->cap; i++) {
        list_free(&hashtable->inner[i]);
    }
    // deallocate the inner array of the table
    free(hashtable->inner);
}
