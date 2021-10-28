/*
 * lab1_2.c
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lab1_2.h"

stack_t stack_new(int capacity) {
    // declare the stack
    stack_t stack;

    // allocate the array that will hold the elements of this stack
    // capacity    -> number of elements
    // sizeof(int) -> the size of one element (an integer)
    stack.data = malloc(capacity * sizeof(int));
    // assign the capacity
    stack.cap = capacity;
    // set the length at 0 (since there are no elements yet)
    stack.len = 0;

    // return the newly-created stack
    return stack;
}

void stack_free(stack_t * stack) {
    // check that the pointer to the stack is not null
    // dereferencing a null pointer is undefined behaviour
    if (stack == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // set the capacity to 0 (the stack will not be able to hold elements
    // anymore)
    stack->cap = 0;
    // set the length to 0 (the elements will be deallocated)
    stack->len = 0;
    // deallocate the array that holds the elements in this stack
    free(stack->data);
    // set the array pointer to NULL to indicate that it is unusable
    stack->data = NULL;
}

bool stack_is_empty(stack_t * stack) {
    // check that the pointer to the stack is not null
    // dereferencing a null pointer is undefined behaviour
    if (stack == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // the stack is empty if it's length is equal to 0 (aka if there are no
    // elements)
    return stack->len == 0;
}

int stack_pop(stack_t * stack) {
    // check that the pointer to the stack is not null
    // dereferencing a null pointer is undefined behaviour
    if (stack == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if the stack is empty, there are no elements we can pop
    if (stack_is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    // get the value from the top of the stack
    int value = stack->data[stack->len - 1];
    // decrease the length by 1 to indicate that this element was removed
    stack->len -= 1;

    // return the popped value
    return value;
}

void stack_push(stack_t * stack, int value) {
    // check that the pointer to the stack is not null
    // dereferencing a null pointer is undefined behaviour
    if (stack == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if the stack is full, we can't push any more elements onto the stack
    //
    // the original implementation does not check if the stack is full. try
    // commenting the next four lines and see what happens when you push more
    // items than the stack can hold (depends on the capacity you give it)
    if (stack->len == stack->cap) {
        printf("The stack is full\n");
        return;
    }

    // add the value at the top of the stack
    stack->data[stack->len] = value;
    // increase the length (number of elements) by 1
    stack->len += 1;
}

void stack_print(stack_t * stack) {
    // check that the pointer to the stack is not null
    // dereferencing a null pointer is undefined behaviour
    if (stack == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // iterate over each element and print it
    for (int i = stack->len - 1; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    // print a new line (for aesthetic purposes)
    printf("\n");
}

int main() {
    // initialize a new stack
    stack_t stack = stack_new(20);

    // initialize the element
    int element = -1;

    // loop indefinetly
    while (1) {
        printf("Append a number (or 0 to stop): ");
        // read an element. no checks are made to see if this is an actual
        // number. see what happens when you try to use a letter instead
        scanf("%d", &element);

        // if the element is 0, break out of the loop
        if (element == 0) {
            break;
        }

        // push the element onto the stack
        stack_push(&stack, element);

        printf("Contents of the stack: ");
        // and then print the contents of the stack
        stack_print(&stack);
    }

    printf("Done\n");

    // while the stack is not empty
    while (!stack_is_empty(&stack)) {
        // pop a value off the stack
        int popped_value = stack_pop(&stack);
        printf("Popped a value off the stack: %d\n", popped_value);

        printf("Contents of the stack: ");
        // and then print the contents of the stack
        stack_print(&stack);
    }

    // deallocate the stack
    stack_free(&stack);

    // return ok
    return 0;
}
