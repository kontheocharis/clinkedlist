#pragma once

#include <stddef.h>

typedef struct ll_Elem {
    void *data;
    struct ll_Elem *next;
} ll_Elem;

// Crate a new linked list with one element
ll_Elem* ll_new(void *data);

// Append a new element to a linked list
ll_Elem* ll_append(ll_Elem *end, void *data);

// Append a new element to a linked list, traversing until the last element is found
ll_Elem* ll_append_t(ll_Elem *some, void *data);

// Insert a new element after *after
ll_Elem* ll_insert(ll_Elem *after, void *data);

// Insert a new element after the index
ll_Elem* ll_insert_index(ll_Elem *begin, size_t after, void *data);

// Set the data of element with index, returning the old data
void* ll_set_index(ll_Elem *begin, size_t index, void *data);

// Remove element after *after from linked list, returning the data
void* ll_pop_after(ll_Elem *after);

// Remove element from linked list at index, returning the data
void* ll_pop_index(ll_Elem *begin, size_t index);

// Get data of element at index
void* ll_get_index(ll_Elem *begin, size_t index);

// Free all members of list (without touching the data)
void ll_free_all(ll_Elem* begin);
