// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>
void freeLinkedList(htab_t *t, size_t i){
    htab_item_t *itemToErase = t->array[i];
    while (itemToErase != NULL){
        htab_item_t *next =  itemToErase->next;
        free((char *)itemToErase->pair.key);
        free(itemToErase);
        itemToErase = next;
    }
}
void htab_clear(htab_t * t){
    for (size_t i = 0; i < t->arr_size ; ++i) {
        if(t->array[i] != NULL){
            freeLinkedList(t, i);
        }
    }
}