/*
 * lab1_3_main.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab1_3.h"

int main() {
    // initialize a new queue
    queue_t queue = queue_new(20);

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

        // add the element in the queue
        queue_enqueue(&queue, element);

        printf("Contents of the queue:\n");
        // and then print the contents of the queue
        queue_print(&queue);
    }

    printf("Done\n");

    // while the queue is not empty
    while (!queue_is_empty(&queue)) {
        // remove a value from the queue
        int popped_value = queue_dequeue(&queue);
        printf("Dequeued a value from the queue: %d\n", popped_value);

        printf("Contents of the queue:\n");
        // and then print the contents of the queue
        queue_print(&queue);
    }

    // deallocate the queue
    queue_free(&queue);

    // return ok
    return 0;
}
