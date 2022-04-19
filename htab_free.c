// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
}