// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework second task of course IJC


#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LENGTH 256
int read_word(char *s, int max, FILE *f){
    if(max > MAX_LENGTH){
        max = MAX_LENGTH;
    }
    int i = 0;
    char c;
    while ((c = fgetc(f)) != EOF){
        if(isspace(c) != 0){
            if(i == 0){
                continue;
            }else{
                break;
            }
        }
        if(i == max -1){
            fprintf(stderr, "Zkraracuju slovo na %d znaku!\n", max);
            break;
        }
        s[i++] = c;
    }
    s[i] = '\0';
    if(c == EOF){
        return c;
    }
    return i;
}
