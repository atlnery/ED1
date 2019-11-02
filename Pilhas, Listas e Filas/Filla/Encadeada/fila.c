#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;
typedef struct no* ptr;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim; //encadeada
    No* ult;
    int qtd;
}Fila;


Fila* fila_criar(); //cria struct fila
Boolean fila_inserir(Fila* f, Tipo elemento); //insere novos nós
void fila_desalocar(Fila* f); //desaloca elementos pilha
Tipo fila_remover1(Fila* f); //remove valor da fila e devolve
Boolean fila_remover2(Fila* f, Tipo* endereco); //grava elemento
Boolean fila_primeiro(Fila* f, Tipo* endereco); //devolve primeiro elemento da fila
int fila_tamanho(Fila* f); //devolve qtd de elementos
Boolean fila_contem(Fila* f, Tipo elemento); //verifica se existe elemento na fila
No* criar_no(Tipo elemento); //cria o nó
void imprime_fila(Fila* f);  //impressão da fila


Fila* fila_criar(){
  Fila* nova = (Fila*)malloc(sizeof(Fila));
  nova->qtd = 0;
  nova->prim = NULL;
  nova->ult = NULL;
  return nova;
}

No* criar_no(Tipo elemento){
  No* new = (No*)malloc(sizeof(No));
  new->dado = elemento;
  new->prox = NULL;
  return new;
}

Boolean fila_inserir(Fila* f, Tipo elemento){
  if (f == NULL) return 0;

  ptr salva = criar_no(elemento);

  if(f->prim == NULL){
    f->prim = salva;
  }
  else{
    f->ult->prox = salva;
  }

  f->ult = salva;
  f->qtd++;
  return 1;
}

Tipo fila_remover1(Fila* f){
  if (f == NULL || f->prim == NULL) return 0;

  Tipo removido = f->prim->dado;
  ptr aux = f->prim->prox;
  free(f->prim);
  f->prim = aux;
  f->qtd--;

  return removido;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
  if (f == NULL || f->prim == NULL) return false;

  *endereco = f->prim->dado;
  ptr aux = f->prim->prox;
  free(f->prim);
  f->prim = aux;
  f->qtd--;

}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
  if (f == NULL || f->prim == NULL) return false;

  *endereco = f->prim->dado;
  return true;
}

int fila_tamanho(Fila* f){
  if (f == NULL) return -1;

  return f->qtd;
}

Boolean fila_contem(Fila* f, Tipo elemento){
  if (f == NULL || f->prim == NULL) return false;

  ptr aux = f->prim;
  while(aux != NULL){
      if(aux->dado == elemento){
        return true;
      }
    aux = aux->prox;
  }
  return false;
}

void imprime_fila(Fila* f){
  if (f->prim == NULL){printf("Fila vazia\n");}

  else{
    printf("ELEMENTOS: [ ");
    ptr aux = f->prim;
    while(aux != NULL){
      printf("%d ", aux->dado);
      aux = aux->prox;
    }
    printf("]\n");
  }
}

void desalocar_no(ptr no){
  if (no == NULL) return;
  desalocar_no(no->prox);
  free(no);
}

void fila_desalocar(Fila* f){
  if (f == NULL) return;

  desalocar_no(f->prim);
  free(f);

}
