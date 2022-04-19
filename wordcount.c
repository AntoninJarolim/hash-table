// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "io.h"
#include "htab.h"
#include "htab_private.h"

#define MAX_LENGTH 256
#define DEBUG 0
#define HTAB_BUCKET_SIZE 13001
/**
 * Podle tohoto zdroje:
 * http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-8.html
 * ocekavam cca 10k unikatnich slov, prvni blizke prvocislo je 13001
 * */

void printLinkedList(htab_t *t, size_t i){
    htab_item_t *itemToPrint = t->array[i];
    bool inside = false;
    while (itemToPrint != NULL){
        if(DEBUG){
            if(inside ){
                printf("\t");
            }
            printf("Array[%ld]: ([key: %s,val: %d], next: %p)\n",\
            i, itemToPrint->pair.key, itemToPrint->pair.value, (void *)itemToPrint->next);
            itemToPrint = itemToPrint->next;
            inside = true;
        }else{
            printf("%s\t%d\n",itemToPrint->pair.key, itemToPrint->pair.value);
            itemToPrint = itemToPrint->next;
        }

    }

}
void printHtab(htab_t * t){
    if(DEBUG){
        printf("---------\n");
        printf("Tabulka ma '%zu' prvku.\n", t->size);
        printf("Array tabulky ma '%zu' prvku.\n", t->arr_size);
        printf("Neprazdne prvky arraye:\n");

    }
    for (size_t i = 0; i < t->arr_size ; ++i) {
        if(t->array[i] != NULL){
            printLinkedList(t, i);
        }
    }
}

void add_fifty(htab_pair_t *pair){
    pair->value += 50;

}
int main (int argc, char *argv[]){
    FILE *fp = stdin;
    char word[MAX_LENGTH];
    htab_t * htab = htab_init(HTAB_BUCKET_SIZE);
    while (read_word(word, 100, fp) != EOF) {
        htab_lookup_add(htab, word);
    }
    printf("\n");

    printHtab(htab);

    fclose(fp);
    htab_free(htab);
    return 0;
}