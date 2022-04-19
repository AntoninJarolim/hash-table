// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    size_t arr_size = t->arr_size;
    for (size_t i = 0; i < arr_size; ++i) {
        htab_item_t *item = t->array[i];
        while(item != NULL){
            (*f)(&item->pair);
            item = item->next;
        }
    }
}
