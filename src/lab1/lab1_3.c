/*
 * lab1_3.c
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lab1_3.h"

queue_t queue_new(int capacity) {
    // declare the new queue
    queue_t queue;

    // allocate memory for the elements of the queue with the requested capacity
    queue.data = malloc(capacity * sizeof(int));
    // set the head index of the queue to 0 as it's empty
    queue.head = 0;
    // set the tail index of the queue to 0 as it's empty
    queue.tail = 0;
    // set the length of the queue to 0 as it's empty
    queue.len = 0;
    // set the capacity of the queue to the requested value
    queue.cap = capacity;

    return queue;
}

void queue_enqueue(queue_t * queue, int value) {
    // check that the pointer to the queue is not null
    // dereferencing a null pointer is undefined behaviour
    if (queue == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if the queue is full, print a failure message and return
    if (queue->len == queue->cap) {
        printf("Queue is full\n");
        return;
    }

    // put the new value at the tail of the queue
    queue->data[queue->tail] = value;
    // increase the length of the queue to accomodate the new value
    queue->len += 1;
    // increase the tail index so that future enqueue operations will write to
    // the proper location in the data array
    queue->tail += 1;

    // if the tail index reached the maximum value it means in must be reset 
    // back to 0 (valid indices range from 0 to capacity - 1)
    // this happens because we use the data array (queue_t::data) in a circular
    // fashion
    if (queue->tail == queue->cap) {
        queue->tail = 0;
    }
}

int queue_dequeue(queue_t * queue) {
    // check that the pointer to the queue is not null
    // dereferencing a null pointer is undefined behaviour
    if (queue == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if the queue is empty, print a failure message and return -1
    if (queue_is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    // get the first value in the queue
    int value = queue->data[queue->head];
    // decrease the length by one - this means we removed a value from the queue
    queue->len -= 1;
    // increase the head index by one fo that future dequeue operations will
    // read from the proper location in the data array
    queue->head += 1;

    // if the head index reached the maximum value it means in must be reset 
    // back to 0 (valid indices range from 0 to capacity - 1)
    // this happens because we use the data array (queue_t::data) in a circular
    // fashion
    if (queue->head == queue->cap) {
        queue->head = 0;
    }

    // return the first value from the queue
    return value;
}

bool queue_is_empty(queue_t * queue) {
    // check that the pointer to the queue is not null
    // dereferencing a null pointer is undefined behaviour
    if (queue == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // the queue is empty if it's length is 0
    return queue->len == 0;
}

void queue_print(queue_t * queue) {
    // check that the pointer to the queue is not null
    // dereferencing a null pointer is undefined behaviour
    if (queue == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // if the queue is empty there is nothing to print
    if (queue_is_empty(queue)) {
        return;
    }

    // iterate over the elements of the queue
    // start from the head of the queue and end after `len`
    for (int i = queue->head; i < queue->head + queue->len; i++) {
        // if the index is within bounds (0 .. queue::capacity) then we can
        // safely use it to read from the data array
        if (i < queue->cap) {
            printf("%d ", queue->data[i]);
        } else {
            // otherwise, it means the index (i is the index) overflowed and so
            // we subtract the capacity from it. this results in a new value
            // that starts from 0 - as if we loop in the [0 .. cap - 1] interval
            printf("%d ", queue->data[i - queue->cap]);
        }
    }

    // print a new line for aesthetic purposes
    printf("\n");
}

void queue_free(queue_t * queue) {
    // check that the pointer to the queue is not null
    // dereferencing a null pointer is undefined behaviour
    if (queue == NULL) {
        printf("Null pointer!\n");
        exit(-1);
    }

    // reset head and tail indeces back to 0
    queue->head = 0;
    queue->tail = 0;
    // set the capacity to 0 (the queue will not be able to hold elements
    // anymore)
    queue->cap = 0;
    // set the length to 0 (the elements will be deallocated)
    queue->len = 0;
    // deallocate the array that holds the elements in this queue
    free(queue->data);
    // set the array pointer to NULL to indicate that it is unusable
    queue->data = NULL;
}

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
