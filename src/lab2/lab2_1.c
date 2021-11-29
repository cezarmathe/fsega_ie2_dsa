/*
 * lab2_1.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab2_1.h"

hashtable_t hashtable_new(int cap) {
    // allocate memory for the inner array of the hashtable
    int * inner = malloc(cap * sizeof(int));

    // initialize all values to -1
    // this hashtable only supports storing only positive integers
    for (int i = 0; i < cap; i++) {
        inner[i] = -1;
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

int hashtable_probe_linear(hashtable_t * hashtable, int key, int probeval) {
    // linear probing attempts to use the next available slot
    return ( hashtable_hash(hashtable, key) + probeval ) % hashtable->cap;
}

int hashtable_insert(hashtable_t * hashtable, int key) {
    // initial probe value - we try to use the first slot available
    int probeval = 0;

    do {
        // get the next potential slot
        int slot_index = hashtable_probe_linear(hashtable, key, probeval);

        // if the slot is empty
        if (hashtable->inner[slot_index] == -1) {
            // assign the key to the slot
            hashtable->inner[slot_index] = key;
            // and return the index of the slot
            return slot_index;
        }

        // otherwise, increase the probe value by 1 - we'll try the next slot in
        // line
        probeval += 1;
    } while (probeval < hashtable->cap);
             // do this while we're within the capacity of the table

    // in case we haven't returned a slot index yet, return -1 to indicate
    // failure in finding an available slot
    return -1;
}

int hashtable_search(hashtable_t * hashtable, int key) {
    // initial probe value - we start searching in the first potential slot
    int probeval = 0;

    do {
        // get the next potential slot
        int slot_index = hashtable_probe_linear(hashtable, key, probeval);

        // if the slot has the key we're searching for
        if (hashtable->inner[slot_index] == key) {
            // reurn the index of the slot
            return slot_index;
        }

        // otherwise, try the next potential slot
        probeval += 1;
    } while (probeval < hashtable->cap);
             // do this while we're within the capacity of the table

    // in case we haven't returned a slot index yet, return -1 to indicate
    // failure in finding a slot that contains the key we're searching for
    return -1;
}

int hashtable_delete(hashtable_t * hashtable, int key) {
    // search for a slot that contains the key we're searching for
    int slot_index = hashtable_search(hashtable, key);

    // if the slot is a positive integer (which means the key exists in a
    // specifc slot), update the slot to contain -1 (which means empty)
    if (slot_index > -1) {
        hashtable->inner[slot_index] = -1;
    }

    // return the slot index of the value that was just deleted
    // this falls back to the -1 returned by `hashtable_search` if the key could
    // not be found
    return slot_index;
}

void hashtable_print(hashtable_t * hashtable) {
    // iterate over each slot in the table
    for (int i = 0; i < hashtable->cap; i++) {
        // if the slot is empty, print a message that says it's empty
        if (hashtable->inner[i] == -1) {
            printf("slot %d: empty\n", i);
        } else {
            // otherwise, print the value contained in that slot
            printf("slot %d: value ( %d )\n", i, hashtable->inner[i]);
        }
    }
}

void hashtable_free(hashtable_t * hashtable) {
    // deallocate the inner array of the table
    free(hashtable->inner);
}
