// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"

htab_t *htab_move(size_t n, htab_t *from){
    // vytvorim novou tabulku
    htab_t *newTab = htab_init(n);

    // presunu vsechny prvky
    htab_item_t * toBeMoved = from->array[0];
    for (size_t i = 1; i < from->arr_size; ++i) {
        while (toBeMoved != NULL){ // posouvam v linked listu
            htab_lookup_add(newTab, toBeMoved->pair.key);
            toBeMoved = toBeMoved->next;
        }
        toBeMoved = from->array[i]; // posouvam v arrayi
    }
    // smazu starou tabulku
    htab_free(from);
    return newTab;
}