/*
 * lab1_2.h
 */

#include <stdbool.h>

#ifndef FSEGA_IE2_DSA_LAB1_2_H
#define FSEGA_IE2_DSA_LAB1_2_H

/**
 * @brief A heap-allocated, non-growable stack.
 */
typedef struct stack_t {
    /**
     * @brief Heap-allocated array that stores the data in this stack.
     */
    int * data;

    /**
     * @brief Maximum capacity that can be stored in this stack.
     *
     * @details The capacity is the maximum number of elements that can be
     * stored in this stack - this means `len` must be less than or equal to
     * `cap`.
     *
     * @attention Not to be confused with length!
     */
    int cap;

    /**
     * @brief Current number of elements in the stack.
     *
     * @attention Not to be confused with capacity!
     */
    int len;
} stack_t;

/**
 * @brief Create a new stack.
 *
 * @param capacity the maximum capacity the stack can hold
 * @return the new stack
 */
stack_t stack_new(int capacity);

/**
 * @brief Deallocate a stack.
 *
 * @warning Calling this function for a stack renders the stack unusable!
 *
 * @param stack the stack
 */
void stack_free(stack_t * stack);

/**
 * @brief Check if the stack is empty.
 *
 * @param stack the stack
 * @return true if the stack is empty, false otherwise
 */
bool stack_is_empty(stack_t * stack);

/**
 * @brief Pop a value from the stack.
 *
 * @param stack the stack
 * @return the value popped from the stack, or -1 (and prints a failure message)
 * if the stack if empty
 */
int stack_pop(stack_t * stack);

/**
 * @brief Push a value onto the stack.
 *
 * @param stack the stack
 * @param value the value
 */
void stack_push(stack_t * stack, int value);

/**
 * @brief Print the contents in a human-readable format.
 *
 * @param stack the stack.
 */
void stack_print(stack_t * stack);

#endif // FSEGA_IE2_DSA_LAB1_2_H
