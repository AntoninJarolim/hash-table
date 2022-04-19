// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC


#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

htab_pair_t * findKeyInLList(htab_t * t, htab_key_t key, size_t index){
    htab_item_t *itemToBeFound = t->array[index];
    while(itemToBeFound != NULL){
        if (strcmp(itemToBeFound->pair.key, key) == 0){
            return &(itemToBeFound->pair);
        }
        itemToBeFound = itemToBeFound->next;
    }
    return NULL;
}

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    size_t arr_size = t->arr_size;
    size_t index = (htab_hash_function(key) % arr_size);
    htab_pair_t *pairToBeFound;
    pairToBeFound = findKeyInLList(t, key, index);
    return pairToBeFound;
}