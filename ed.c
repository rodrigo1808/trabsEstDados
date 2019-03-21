#include <stdio.h>
#include <stdlib.h>

char alphabet[] = "ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *text;
int nwords;

void textIterate() {
    int i=0;
    int initial = 0;
    int final = 0;
    while (text[i] != '\0') {
        if(text[i] == ' ') {
            final = i;
        }
        else {
            
        }
        i++;
    }
}

void savingWord() {

}

void search() {
    
}

int main() {
    text = malloc(50*sizeof(char));
    gets(text);
    wordsCounter();
    free(text);
    return 0;
}