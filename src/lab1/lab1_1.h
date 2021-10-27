/*
 * lab1_1.h
 */

#ifndef FSEGA_IE2_DSA_LAB1_1_H
#define FSEGA_IE2_DSA_LAB1_1_H

/**
 * @brief A node in a linked list.
 */
typedef struct list_node_t {
    /**
     * @brief Key of this node.
     */
    int key;

    /**
     * @brief Address of the previous node.
     */
    struct list_node_t * prev;

    /**
     * @brief Address of the next node.
     */
    struct list_node_t * next;
} list_node_t;

/**
 * @brief A linked list.
 */
typedef struct list_t {
    /**
     * @brief The first node in the list.
     */
    list_node_t * head;
} list_t;

/**
 * @brief Create a new linked list.
 *
 * @return a new linked list
 */
list_t list_new();

/**
 * @brief Delete a node from the list.
 *
 * @param list the linked list
 * @param node the node that should be deleted
 */
void list_delete(list_t * list, list_node_t * node);

/**
 * @brief Deallocate a list.
 *
 * @param list the linked list
 */
void list_free(list_t * list);

/**
 * @brief Insert a new key in the list.
 *
 * @param list the linked list
 * @param key the key that should be inserted
 */
void list_insert(list_t * list, int key);

/**
 * @brief Print a list to stdout in a human-readable format.
 *
 * @param list the linked list.
 */
void list_print(list_t * list);

/**
 * @brief Search for a node in a linked list.
 *
 * @param list the linked list
 * @param key the key indentifying the desired node
 * @return list_node_t* the corresponding node, or NULL if not found
 */
list_node_t * list_search(list_t * list, int key);

#endif // FSEGA_IE2_DSA_LAB1_1_H
