/*
 * lab2_2.h
 */

#include "lab1_1.h"

#ifndef FSEGA_IE2_DSA_LAB2_2_H
#define FSEGA_IE2_DSA_LAB2_2_H

/**
 * @brief A hash table with support for positive integers.
 */
typedef struct hashtable_t {
    /**
     * @brief Inner array that stores the contents of the hashtable.
     */
    list_t * inner;

    /**
     * @brief The capacity of this hashtable.
     */
    int cap;
} hashtable_t;

/**
 * @brief Create a new hashtable.
 *
 * @param cap capacity
 * @return hashtable_t
 */
hashtable_t hashtable_new(int cap);

/**
 * @brief Compute the hash of a certain key.
 *
 * @param hashtable provides the modulo (capacity)
 * @param key
 * @return hash
 */
int hashtable_hash(hashtable_t * hashtable, int key);

/**
 * @brief Insert a value in the hashtable.
 *
 * @param hashtable
 * @param key
 * @return slot in the table where the value was inserted
 */
int hashtable_insert(hashtable_t * hashtable, int key);

/**
 * @brief Search for a value in the hashtable.
 *
 * @param hashtable
 * @param key
 * @return slot in the table where the value is located or -1 if the value was
 *         not found
 */
int hashtable_search(hashtable_t * hashtable, int key);

/**
 * @brief Delete a value from the hashtable.
 *
 * @param hashtable
 * @param key
 * @return slot in the table where the value is located or -1 if the value was
 *         not found
 */
int hashtable_delete(hashtable_t * hashtable, int key);

/**
 * @brief Print the contents of the hashtable.
 *
 * @param hashtable
 */
void hashtable_print(hashtable_t * hashtable);

/**
 * @brief Deallocate the memory used by the hashtable.
 *
 * @warning The hashtable is unusable after using this function!
 *
 * @param hashtable
 */
void hashtable_free(hashtable_t * hashtable);

#endif //FSEGA_IE2_DSA_LAB2_2_H
