/*
 * lab1_2_main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab1_2.h"

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
