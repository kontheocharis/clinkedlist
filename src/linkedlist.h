#pragma once

#include <stddef.h>

// The structure representing a linked-list.
struct ll_t {
    struct ll_t *next;
    void *data;
};

// Crate a new linked list with one element
struct ll_t *ll_new(void *data);

// Append a new element to a linked list
struct ll_t *ll_append(struct ll_t *end, void *data);

// Append a new element to a linked list, traversing until the last element is
// found
struct ll_t *ll_append_t(struct ll_t *some, void *data);

// Insert a new element after *after
struct ll_t *ll_insert(struct ll_t *after, void *data);

// Insert a new element after the index
struct ll_t *ll_insert_index(struct ll_t *begin, size_t after, void *data);

// Set the data of element with index, returning the old data
void *ll_set_index(struct ll_t *begin, size_t index, void *data);

// Remove element after *after from linked list, returning the data
void *ll_pop_after(struct ll_t *after);

// Remove element from linked list at index, returning the data
void *ll_pop_index(struct ll_t *begin, size_t index);

// Get data of element at index
void *ll_get_index(struct ll_t *begin, size_t index);

// Free all members of list (without touching the data)
void ll_free_all(struct ll_t *begin);
