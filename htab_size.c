// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"
size_t htab_size(const htab_t * t){
    size_t size = t->size;
    return size;
}