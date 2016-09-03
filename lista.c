//Lista em C
//Helton F. Varela

#include <stdio.h>
#include <stdlib.h>

//Estrutura auto-referenciada
struct estruturaNo{
  char dado;//informação a ser armazenada
  struct No *proxPtr;//ponteiro que aponta para o próximo Nó
};

//Definição de nomes
typedef struct estruturaNo No;// define o tipo estruturaNo para No
typedef No *NoPtr;// define o tipo No para um ponteiro

//Protótipos

int main(){
  system("clear");

  //Menu
  int op;
  char item;

  printf("Digite sua escolha:\n");
  printf(" 1 para inserir na lista:\n");
  printf(" 2 para remover da lista:\n");
  printf(" 3 sair:\n");


  NoPtr cabeca = NULL;//cria uma variável dinamica(ponteiro) que aponta para NULL

  return 0;
}
