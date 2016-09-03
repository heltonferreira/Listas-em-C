//Lista em C
//Helton F. Varela

#include <stdio.h>
#include <stdlib.h>

//Estrutura auto-referenciada
struct estruturaNo{
  char dado;//informação a ser armazenada
  struct No *proxPtr;//ponteiro que aponta para o próximo Nó
};

//Definição de nome
typedef struct estruturaNo No;// define o tipo estruturaNo para No

//Protótipos
void inserir(No **inicioPtr, char informacao);//ponteiro que aponta para o inicio(como se fosse uma nova cabeca) e a informacao a ser armazenada
void imprime(No *atualPtr);//recebe o ponteiro do no atual para imprimir os valores

int main(){
  system("clear");

  int op;
  char item;
  No *cabeca = NULL;//cria uma variável dinamica(ponteiro) que aponta para NULL

  //Menu
  printf("Digite sua escolha:\n");
  printf(" 1 para inserir na lista:\n");
  printf(" 2 para remover da lista:\n");
  printf(" 3 imprimir lista:\n");
  printf(" 4 sair\n");
  scanf("%d", &op);

  switch(op){
    case 1:
      inserir(&cabeca, 'a');//cabeca ja contem um endereco(NULL), &cabeca eh um endereco para outro endereco(lembre-se que o parametro eh um ponteiro para ponteiro, portanto eh necessario passar o "endereco de um endereco")
      break;

    case 2:
      break;

    case 3:
      imprime(cabeca);
      break;

    default:
      break;
  }

  return 0;
}

void inserir(No **inicioPtr, char valor){//ponteiro para ponteiro, pois aponta para o ponteiro *novo
  No *novoPtr, *anteriorPtr, *atualPtr;
  novoPtr = malloc(sizeof(No));//aloca um bloco de bytes consecutivos na memória RAM do computador e devolve o endereço desse bloco
  if(novoPtr!=NULL){//se tiver um endereco armazenado, significa que há espaco disponivel, entao
    novoPtr->dado = valor;//o ponteiro que aponta para um novo no, recebe um valor e o atribui no campo dado
    novoPtr->proxPtr = NULL;//o ponteiro que aponta para um novo no, recebe NULL para o campo que aponta para o proximo ponteiro

    anteriorPtr = NULL; //o ponteiro que aponta para o no anterior, recebe como endereco NULL
    atualPtr = *inicioPtr;//o ponteiro que aponta para o no atual, recebe como endereco o conteudo de inicioPtr(lembre-se que o conteudo de inicioPtr tbm eh um endereco, pois inicioPtr eh um ponteiro para ponteiro)
  }
}

void imprime(No *atualPtr){
    if(atualPtr == NULL){//se o ponteiro que aponta para o no atual aponta para lugar nenhum(endereco vazio)
        printf("A lista está vazia\n");
    }
    else{
        printf("Lista: \n");
        while(atualPtr!=NULL){//enquanto o ponteiro que aponta para o no atual, conter um endereco de memoria(diferente de NULL)
          printf("%c --> ", atualPtr->dado);
        }
    }

}
