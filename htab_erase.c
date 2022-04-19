// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool eraseKeyInLList(htab_t * t, htab_key_t key, size_t index){
    htab_item_t *itemToErase = t->array[index];
    while(itemToErase != NULL){
        if (strcmp(itemToErase->pair.key, key) == 0){
            free((char *)itemToErase->pair.key);
            free(itemToErase);
            return 1;
        }
        itemToErase = itemToErase->next;
    }
    return 0;
}

bool htab_erase(htab_t * t, htab_key_t key){
    size_t arr_size = t->arr_size;
    size_t index = (htab_hash_function(key) % arr_size);
    bool erased = eraseKeyInLList(t, key, index);
    return erased;
}