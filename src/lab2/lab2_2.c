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

    // initialize all values to -1
    // this hashtable only supports storing only positive integers
    for (int i = 0; i < cap; i++) {
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
    int hash = hashtable_hash(hashtable, key);
    list_insert(&hashtable->inner[hash], key);
    return hash;
}

int hashtable_search(hashtable_t * hashtable, int key) {
    int hash = hashtable_hash(hashtable, key);
    if (list_search(&hashtable->inner[hash], key) == NULL) {
        return -1;
    }
    return hash;
}

int hashtable_delete(hashtable_t * hashtable, int key) {
    int hash = hashtable_hash(hashtable, key);
    list_node_t * node = list_search(&hashtable->inner[hash], key);
    if (node == NULL) {
        return -1;
    }
    list_delete(&hashtable->inner[hash], node);
    return hash;
}

void hashtable_print(hashtable_t * hashtable) {
    // iterate over each slot in the table
    for (int i = 0; i < hashtable->cap; i++) {
        printf("   slot %d\n", i);
        list_print(&hashtable->inner[i]);
    }
}

void hashtable_free(hashtable_t * hashtable) {
    // deallocate the inner array of the table
    for (int i = 0; i < hashtable->cap; i++) {
        list_free(&hashtable->inner[i]);
    }
    free(hashtable->inner);
}
