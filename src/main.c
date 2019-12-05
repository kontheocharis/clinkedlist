#include <stdio.h>
#include "linkedlist.h"
#include <assert.h>

typedef struct {
    int x; int y;
} Coordinate;

int main(int argc, char *argv[])
{
    Coordinate first_coord  = { 1, 2 };
    Coordinate second_coord = { 3, 4 };
    Coordinate third_coord  = { 5, 6 };
    Coordinate fourth_coord = { 7, 8 };

    ll_Elem *first_element =  ll_new(&first_coord);
    ll_Elem *second_element = ll_append(first_element, &second_coord);
    ll_Elem *third_element = ll_append(second_element, &third_coord);

    ll_Elem *fourth_element = ll_append_t(first_element, &fourth_coord);

    /* printf("%i", ((Coordinate*) ll_get_index(first_element, 3))->x); */

    ll_free_all(first_element);

    printf("%i", ((Coordinate*)first_element->data)->x);

    return 0;
}
