/*
 * lab1_3.h
 */

#include <stdbool.h>

#ifndef FSEGA_IE2_DSA_LAB1_3_H
#define FSEGA_IE2_DSA_LAB1_3_H

/**
 * @brief A queue.
 */
typedef struct queue_t {
    /**
     * @brief Array that holds the items in this queue.
     */
    int * data;

    /**
     * @brief Index of the first element in the queue.
     */
    int head;

    /**
     * @brief Index of the last element in the queue.
     */
    int tail;

    /**
     * @brief Length - number of items currently in the queue.
     */
    int len;

    /**
     * @brief Capacity - maximum number of items that this queue can hold.
     * 
     */
    int cap;
} queue_t;

/**
 * @brief Create a new queue.
 * 
 * @param capacity Maximum number of elements this queue will be able to hold.
 * @return a new queue 
 */
queue_t queue_new(int capacity);

/**
 * @brief Add a new item to the queue.
 * 
 * @param queue the queue
 * @param value the value to be added in the queue
 */
void queue_enqueue(queue_t * queue, int value);

/**
 * @brief Remove an item from the queue.
 * 
 * @param queue the queue
 * @return the value, or -1 and prints a failure message if empty 
 */
int queue_dequeue(queue_t * queue);

/**
 * @brief Check if the queue is empty.
 * 
 * @param queue the queue
 * @return true if empty, false otherwise 
 */
bool queue_is_empty(queue_t * queue);

/**
 * @brief Print the queue in a human-readable format.
 * 
 * @param queue the queue
 */
void queue_print(queue_t * queue);

/**
 * @brief Deallocate a queue.
 * 
 * @attention This renders the queue unusable! 
 */
void queue_free(queue_t * queue);

#endif // FSEGA_IE2_DSA_LAB1_3_H
