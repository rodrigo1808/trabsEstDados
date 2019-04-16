#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void) {
  
  // Pilha de Números
  int *pilhaNum;
  pilhaNum = malloc(MAX*sizeof(int));

  // Pilha de Operadores
  char *pilhaOpc;
  pilhaOpc = malloc(MAX*sizeof(char));

  // String para receber o input
  char expressao[20];

  // Index para percorrer a input
  int i = 0;

  // Leitura do Input
  while(!feof(stdin)) {
    scanf("%s",expressao);
  }

  // Estrura para percorrer todo o input
  while(expressao[i] != '\0') {

    // Se for ) não faz nada
    if(expressao[i] == '(') {   
      i++;
      continue;
    }

    // Se for um operador, armazena na pilha de operadores
    if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/') {
      *pilhaOpc = expressao[i];
      pilhaOpc++;
      i++;
      continue;
    }

    // Se for ) calcula a partir dos dois numeros e do operador do topo das listas
    if(expressao[i] == ')') {
      int f1, f2, result;
      pilhaNum--;
      f2 = *pilhaNum;
      pilhaNum--;
      f1 = *pilhaNum;
      pilhaOpc--;

      switch ( *pilhaOpc ) {

        case '+':
        result = f1 + f2;
        break;

        case '-':
        result = f1 - f2;
        break;

        case '*':
        result = f1 * f2;
        break;

        case '/':
        result = f1 / f2;
        break;

      }

      *pilhaNum = result;
      pilhaNum++;

      i++;
      continue;
    }

    // Se não for nenhum dos casos anteriores, é um número, logo adiciona à pilha de numeros
    int value = expressao[i] - '0';
    *pilhaNum = value;
    pilhaNum++;
    i++;
  }

  // Printa resposta final
  pilhaNum--;
  printf("%d", *pilhaNum);

}