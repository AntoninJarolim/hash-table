// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC


#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

// table constructor
htab_t *htab_init(size_t n){
    htab_t * new_htab = malloc(sizeof(htab_t) + sizeof(htab_item_t*) *n);
    if(new_htab == NULL){
        return NULL;
    }
    new_htab->size = 0;
    new_htab->arr_size = n;
    for (size_t i = 0; i < n; ++i) {
        new_htab->array[i] = NULL;
    }
    return new_htab;
}
