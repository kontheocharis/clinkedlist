#include "linkedlist.h"
#include "assert.h"
#include "stdlib.h"

ll_Elem* ll_new(void *data)
{
    ll_Elem *new = malloc(sizeof(ll_Elem));
    new->data = data;
    new->next = NULL;

    return new;
}

ll_Elem* ll_append(ll_Elem *end, void *data)
{
    ll_Elem *new = ll_new(data);
    end->next = new;

    return new;
}

ll_Elem* ll_append_t(ll_Elem *some, void *data)
{
    while (some->next) some = some->next;
    return ll_append(some, data);
}

ll_Elem* ll_insert(ll_Elem *after, void *data)
{
    ll_Elem *new = ll_new(data);
    new->next = after->next;
    after->next = new;

    return new;
}

ll_Elem* ll_insert_index(ll_Elem *begin, size_t after, void *data)
{
    ll_Elem *curr = begin;
    for (size_t i = 0; i < after; ++i) curr = curr->next;

    return ll_insert(curr, data);
}

void* ll_set_index(ll_Elem *begin, size_t index, void *data)
{
    ll_Elem *curr = begin;
    for (size_t i = 0; i <= index; ++i) curr = curr->next;

    void *old_data = curr->data;
    curr->data = data;

    return old_data;
}

void* ll_pop_after(ll_Elem *after)
{
    void *old_data = after->next->data;

    ll_Elem *next = after->next->next;
    free(after->next);
    after->next = next;

    return old_data;
}

void* ll_pop_index(ll_Elem *begin, size_t index)
{
    if (index == 0)
    {
        void *old_data = begin->data;
        free(begin);
        return old_data;
    }

    ll_Elem *curr = begin;
    for (size_t i = 0; i < index - 1; ++i) curr = curr->next;

    return ll_pop_after(curr);
}

void* ll_get_index(ll_Elem *begin, size_t index)
{
    ll_Elem *curr = begin;
    for (size_t i = 0; i < index; ++i) curr = curr->next;

    return curr->data;
}

void ll_free_all(ll_Elem *begin)
{
    if (begin->next != NULL) ll_free_all(begin->next);
    free(begin);
}
