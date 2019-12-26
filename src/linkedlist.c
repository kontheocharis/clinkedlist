#include "linkedlist.h"

#include <stdlib.h>

struct ll_t *ll_new(void *data)
{
    struct ll_t *new = malloc(sizeof(struct ll_t));
    new->data = data;
    new->next = NULL;

    return new;
}

struct ll_t *ll_append(struct ll_t *end, void *data)
{
    struct ll_t *new = ll_new(data);
    end->next = new;

    return new;
}

struct ll_t *ll_append_t(struct ll_t *some, void *data)
{
    while (some->next) some = some->next;
    return ll_append(some, data);
}

struct ll_t *ll_insert(struct ll_t *after, void *data)
{
    struct ll_t *new = ll_new(data);
    new->next = after->next;
    after->next = new;

    return new;
}

struct ll_t *ll_insert_index(struct ll_t *begin, size_t after, void *data)
{
    struct ll_t *curr = begin;
    for (size_t i = 0; i < after; ++i) curr = curr->next;

    return ll_insert(curr, data);
}

void *ll_set_index(struct ll_t *begin, size_t index, void *data)
{
    struct ll_t *curr = begin;
    for (size_t i = 0; i <= index; ++i) curr = curr->next;

    void *old_data = curr->data;
    curr->data = data;

    return old_data;
}

void *ll_pop_after(struct ll_t *after)
{
    void *old_data = after->next->data;

    struct ll_t *next = after->next->next;
    free(after->next);
    after->next = next;

    return old_data;
}

void *ll_pop_index(struct ll_t *begin, size_t index)
{
    if (index == 0)
    {
        void *old_data = begin->data;
        free(begin);
        return old_data;
    }

    struct ll_t *curr = begin;
    for (size_t i = 0; i < index - 1; ++i) curr = curr->next;

    return ll_pop_after(curr);
}

void *ll_get_index(struct ll_t *begin, size_t index)
{
    struct ll_t *curr = begin;
    for (size_t i = 0; i < index; ++i) curr = curr->next;

    return curr->data;
}

void ll_free_all(struct ll_t *begin)
{
    if (begin->next) ll_free_all(begin->next);
    free(begin);
}
