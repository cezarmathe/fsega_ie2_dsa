/*
 * lab2_1.h
 */

#ifndef FSEGA_IE2_DSA_LAB2_1_H
#define FSEGA_IE2_DSA_LAB2_1_H

/**
 * @brief A hash table.
 */
typedef struct hashtable_t {
    int * inner;
    int cap;
} hashtable_t;

hashtable_t hashtable_new(int cap);

int hashtable_hash(hashtable_t * hashtable, int key);

int hashtable_probe_linear(hashtable_t * hashtable, int key, int i);

// int hashtable_probe_quadratic(hashtable_t * hashtable, int k, int i);

// int hashtable_probe_double_hash(hashtable_t * hashtable, int k, int i);

int hashtable_insert(hashtable_t * hashtable, int key);

int hashtable_search(hashtable_t * hashtable, int key);

int hashtable_delete(hashtable_t * hashtable, int key);

void hashtable_print(hashtable_t * hashtable);

void hashtable_free(hashtable_t * hashtable);

#endif //FSEGA_IE2_DSA_LAB2_1_H
