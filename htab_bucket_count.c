// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"

size_t htab_bucket_count(const htab_t * t){
    size_t arr_size = t->arr_size;
    return arr_size;
}