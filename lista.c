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

  int op;
  char item;
  No *cabeca = NULL;//cria uma variável dinamica(ponteiro) que aponta para NULL

  //Menu
  system("clear");
  printf("Digite sua escolha:\n");
  printf(" 1 para inserir na lista:\n");
  printf(" 2 para remover da lista:\n");
  printf(" 3 imprimir lista:\n");
  printf(" 4 sair\n");
  scanf("%d", &op);
  setbuf(stdin, NULL);

  while(op!=4){
    switch(op){
      case 1:
          printf("Digite um caractere:\n");
          scanf("\n%c", &item);
          setbuf(stdin, NULL);
          inserir(&cabeca, item);//cabeca ja contem um endereco(NULL), &cabeca eh um endereco para outro endereco(lembre-se que o parametro eh um ponteiro para ponteiro, portanto eh necessario passar o "endereco de um endereco")
          imprime(cabeca);
          break;

      case 2:
        break;

      case 3:
          imprime(cabeca);
        break;

      default:
          printf("Escolha invalida\n");
        break;
      }

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

    while(atualPtr!=NULL && valor > atualPtr->dado){//se o ponteiro que aponta para o no atual, existir e o valor inserido for mais que o do no atual
        anteriorPtr = atualPtr;//o anterior agora eh o atual
        atualPtr = atualPtr->proxPtr;//o atual agora eh o proximo
    }
    if(anteriorPtr == NULL){//se o ponteiro que aponta para o no anterior apontar para lugar nenhum
        novoPtr->proxPtr = *inicioPtr;//o ponteiro que aponta para um novo no, no campo proximo(que aponta para um proximo no) recebe o endereco da cabeca
        *inicioPtr = novoPtr;//o conteudo de inicioPtr(que eh um endereco pois no parametro eh um ponteiro para ponteiro) recebe o endereco que aponta para a cabeca
    }
    else{//se o ponteiro que aponta para o no anterior apontar para algum lugar
        anteriorPtr->proxPtr = novoPtr;//o ponteiro que aponta para o no anterior, no campo proximo recebe o novo no
        novoPtr->proxPtr = atualPtr;//o campo proximo do novo ponteiro, recebe o ponteiro que aponta para o no atual
    }
  }
  else{
      printf("%c não inserido. Nao ha memoria disponivel\n", valor);
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
          atualPtr = atualPtr->proxPtr;//ponteiro que aponta para o no atual, recebe o endereco do proximo ponteiro
        }
        printf("NULL\n\n");
    }
}
