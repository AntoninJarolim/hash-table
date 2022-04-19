// Created by Antonín Jarolím on 15.04.2021.
// VUT v Brně, Fakulta informačních technologií
// Solution of second homework first task of course IJC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int getCFileStdin(FILE *fptr){
    int c;
    if(fptr != NULL){
        c = fgetc(fptr);
    }else{
        c = getchar();
    }
    return c;
}

int main(int argc, char * argv[]){
    bool toend = 0;
    int nlines = 10; // impicitne tisknu 10 radku
    char *filename = NULL;
    if(argc == 2){
        filename = argv[1];
    }
    if(argc > 2){
        if(argv[2][0] == '+'){
            toend=1;
        }
        nlines = atoi(argv[2]);
        if(nlines <= 0){
            fprintf(stderr, "Error: Za parametrem -n ocekavano cislo vetsi nez 0!\n");
            return 1;
        }
        if(argc == 4){
            filename = argv[3];
        }
    }

    FILE *fptr;
    if(filename != NULL){
        if ((fptr = fopen(filename,"r")) == NULL){
            fprintf(stderr, "Error: Neporadilo se precist soubor!\n");
            return 1;
        }
    }
    int c;
    if(toend == 1 ){
        size_t fromLine = nlines-1;
        while ((c = getCFileStdin(fptr)) != EOF){
            if(fromLine < 1){
                printf("%c",c);
            }else{
                if(c == '\n'){
                    fromLine--;
                }
            }
        }
        return 0;
    }

    int max_line_lenght = 1001 ; // -1 ('\0' char)
    char **lines = (char**) malloc(sizeof(char*) * nlines);
    for(int i = 0; i < nlines; i++){
        lines[i] = (char*)calloc(max_line_lenght, sizeof(char));
    }

    size_t i = 0; // char index count
    size_t l = 0; // line index count
    size_t last_line = nlines ;
    bool printShortening = 1;
    while((c = getCFileStdin(fptr)) != EOF){
        if(c == '\n'){ // na konec radku dam ukoncovaci null a posunu line do ktere zapisuju
            lines[l++][i++] = '\0';
            if(l == last_line) {
                l = 0;
            }
            i = 0;
        }else{ // kdyz znak neni '\n' tak do momentalni liny pripisuju znaky
            if(max_line_lenght - 1 > i){ // jen pokud jsem neprekorocil limit
                lines[l][i++] = c;
            }else if(printShortening){
                fprintf(stderr, "Warning: Delka radku prekrocena - zkracuju!\n");
                printShortening = 0;
            }
        }
    }
    lines[l++][i] = '\0';
    size_t firstLineToWrite = l;
    // zacnu vypisovat liny, do konce arraye s liny
    for (int j = firstLineToWrite; j < nlines; ++j) {
        if(lines[j][0] != 0){ // liny, do kterych nebylo nic zapsano, se nevypisou
            printf("%s\n", lines[j]);
        }
    }
    // dovypisu vsechny liny, ktere jeste nebyly vypsany
    for (int j = 0; j < firstLineToWrite; ++j) {
        if(lines[j][0] != 0){
            printf("%s\n", lines[j]);
        }
    }
    if (fptr != NULL){
        fclose(fptr);
    }
    return 0;
}