/*
 * lab2_1.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab2_1.h"

hashtable_t hashtable_new(int cap) {
    int * inner = malloc(cap * sizeof(int));
    for (int i = 0; i < cap; i++) {
        inner[i] = -1;
    };
    hashtable_t hashtable;
    hashtable.inner = inner;
    hashtable.cap = cap;
    return hashtable;
}

int hashtable_hash(hashtable_t * hashtable, int key) {
    return key % hashtable->cap;
}

int hashtable_probe_linear(hashtable_t * hashtable, int key, int i) {
    return ( hashtable_hash(hashtable, key) + i ) % hashtable->cap;
}

int hashtable_insert(hashtable_t * hashtable, int key) {
    int i = 0;

    do {
        int j = hashtable_probe_linear(hashtable, key, i);
        if (hashtable->inner[j] == -1) {
            hashtable->inner[j] = key;
            return j;
        }
        i += 1;
    } while (i < hashtable->cap);

    return -1;
}

int hashtable_search(hashtable_t * hashtable, int key) {
    int i = 0;
    int j = 0;

    do {
        int j = hashtable_probe_linear(hashtable, key, i);
        if (hashtable->inner[j] == key) {
            return j;
        }
        i += 1;
    } while (i < hashtable->cap && hashtable->inner[j] == -1);

    return -1;
}

int hashtable_delete(hashtable_t * hashtable, int key) {
    int j = hashtable_search(hashtable, key);
    if (j > -1) {
        hashtable->inner[j] = -1;
        return j;
    }
    return -1;
}

void hashtable_print(hashtable_t * hashtable) {
    for (int i = 0; i < hashtable->cap; i++) {
        if (hashtable->inner[i] == -1) {
            printf("slot %d: empty\n", i);
        } else {
            printf("slot %d: value ( %d )\n", i, hashtable->inner[i]);
        }
    }
}

void hashtable_free(hashtable_t * hashtable) {
    free(hashtable->inner);
}
