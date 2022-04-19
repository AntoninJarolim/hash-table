// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC

// this file implements sctruct using in htab
#ifndef __HTAB_H_PRIVATE__
#define __HTAB_H_PRIVATE__
#include "htab.h"
#include <stdio.h>
typedef struct htab_item htab_item_t;
struct htab_item{
    htab_pair_t pair;
    htab_item_t * next;
};

struct htab{
    size_t size;
    size_t arr_size;
    htab_item_t * array[];
};
typedef struct htab htab_t;


#endif