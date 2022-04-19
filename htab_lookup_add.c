// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC


#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>


htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    // zjisti kolik indexu tabulky mas
    size_t arr_size = t->arr_size;
    // vypocitej index pres hash funci
    size_t index = (htab_hash_function(key) % arr_size);
    // ziskej posledni pointer na item v linked listu
    htab_item_t **lastItem = &t->array[index];
    while (*lastItem != NULL){ // prohledavam tabulku
        if((strcmp((*lastItem)->pair.key, key)) == 0){ // kdyz uz je key v tabulce
            (*lastItem)->pair.value++;
            return &((*lastItem)->pair); // tak value++ a vracim jeho pointer
        }
        lastItem = &((*lastItem)->next);
    }


    // vytvoreni noveho itemu
    htab_item_t *newitem = malloc(sizeof(htab_item_t));
    if(newitem == NULL){
        fprintf(stderr, "Memory allocation failed.");
    }
    newitem->pair.value = 1;
    newitem->next = NULL;
    char *newstring = calloc(sizeof(char), strlen(key) + 1);
    if(newitem == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
    }
    strcpy(newstring, key);
    newitem->pair.key = newstring;
    *lastItem = newitem; // prirazeni noveho itemu
    t->size++;


    return &newitem->pair;
    // kdysi si mel funkci
    // htab_item_t **last = getLast(t, index);

    //

}