#include <stdio.h>
#include <string.h>
#define MAX 10000

char ranking[MAX][30];
int qtdvezes[MAX];
int nelem=0;

int main() {
    char word[30];
    int addcontrol = 1;
    //char debug[30];
    int i;
    int k;

    // Lendo a entrada até o eof
    while(!feof(stdin)) {
        if(scanf("%s",word)!=0){
            // Verificando se já existe, se sim aumenta em qtdvezes
            for(i=0; i<nelem; i++){
              if(strcmp(word, ranking[i])==0){
                qtdvezes[i] += 1;
                addcontrol=0;
                break; 
              }
            }

            // Senão acrescenta na matriz e poe a qtdvezes para 1
            if(addcontrol == 1) {
              strcpy(ranking[nelem],word);
              qtdvezes[nelem] = 1;
              nelem+=1;
            }

            //strcpy(debug, word);
            addcontrol = 1;
        }
    }

    /*for(i=0; i<nelem; i++){
      if(strcmp(debug, ranking[i])==0) {
        qtdvezes[i]-=1;
      }
    }*/

    char wordaux[30];
    int qtdaux;
    for(i=0; i<nelem; i++) {
      for(k=0; k<nelem; k++) {
        if(strcmp(ranking[i],ranking[k]) < 0) {
          strcpy(wordaux, ranking[i]);
          qtdaux = qtdvezes[i];
          
          strcpy(ranking[i], ranking[k]);
          qtdvezes[i] = qtdvezes[k];

          strcpy(ranking[k], wordaux);
          qtdvezes[k] = qtdaux;
        }
      }
    }

    for(i=0; i<nelem; i++){
        printf("%s - %d\n",ranking[i], qtdvezes[i]);
    }
}