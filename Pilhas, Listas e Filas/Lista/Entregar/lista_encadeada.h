#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;
typedef struct no* ptr;

typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* first;
    No* last;
    int qtd;
}Lista;


Lista* lista_criar(); //cria lista
void lista_destruir(Lista* l);

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao); //função principal de inserção
Boolean lista_inserir_fim(Lista* l, Tipo elemento); //insere os elementos no final da fila
Boolean lista_insere_inicio(Lista*l, Tipo elemento); // insere os elementos no inicio da fila

int* lista_remover1(Lista* l, int posicao); //remove elemento e DEVOLVE o valor
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco); //remove o elemento e guarda em variável
Boolean lista_remover_elemento(Lista* l, Tipo elemento);

Boolean lista_buscar(Lista* l, int posicao, int* endereco); //busca posição e guarda elemento correspondente em endereco;
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);

int lista_tamanho(Lista* l); //retorna qtd de elementos na lista;
void lista_imprimir(Lista* l); //imprime valores da lista;

No* criar_no(Tipo elemento, ptr ant, ptr prox); //cria os nós que fazem parte da lista
void busca_no(Lista* l, int posicao, ptr* anterior, ptr* prox); //busca posição específica


Lista* lista_criar(){

  Lista* Nova = (Lista*) malloc(sizeof(Lista));
  Nova->first = Nova->last = NULL;
  Nova->qtd = 0;
  return Nova;
}


Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){

  if (l == NULL)return false;
    
  else if (posicao > l->qtd) return false;

  else if(posicao == l->qtd){
    lista_inserir_fim(l, elemento);
    return true;
  }

  else if(posicao == 0){
    lista_insere_inicio(l, elemento);
    return true;
  }

  else{
    ptr anterior;
    ptr proximo;

    busca_no(l, posicao, &anterior, &proximo);
    No* novo = criar_no(elemento, anterior, proximo);

    novo->ant = anterior;
    novo->prox = proximo;
    novo->ant->prox = novo;
    novo->prox->ant = novo;
    l->qtd++;
  }
}

Boolean lista_inserir_fim(Lista* l, Tipo elemento){

  if(l == NULL) return false;

  if(l->qtd == 0){
    No* no = criar_no(elemento, NULL, NULL);
    l->first = l->last = no;
  }

  else{
    No* no = criar_no(elemento, l->last, NULL);
    l->last->prox = no;
    l->last = no;
  }

  l->qtd++;
  return true;
}

Boolean lista_insere_inicio(Lista* l, Tipo elemento){
  if(l == NULL) return false;

  No* no = criar_no(elemento, NULL, NULL);

  if(l->qtd == 0){
    lista_inserir_fim(l, elemento);
    return true;
  }

  else{
    no->prox = l->first;
    l->first->ant = no;
    l->first = no;
    l->qtd++;
  }
}


int* lista_remover1(Lista* l, int posicao){

  if(posicao >= l->qtd){ printf("POSIÇÃO INVÁLIDA!\n"); return NULL;}
  if(l->first == NULL) return NULL;
  if (l->qtd == 0)return NULL;

   ptr anterior;
   ptr proximo;
   int* valor;

   if(posicao == (l->qtd-1) && posicao != 0){
     valor = &l->last->dado;
     l->last = l->last->ant;
     l->last->prox = NULL;
   }

    else if(posicao == 0){
        valor = &l->first->dado;
       
        if (l->qtd == 1){l->first = NULL;}
        else{
            l->first = l->first->prox;
            l->first->ant = NULL;
        }
    }

    else{
      busca_no(l, posicao, &anterior, &proximo);
      valor = &anterior->prox->dado;
      anterior->prox = proximo->prox;
      proximo->prox->ant = proximo->ant;
    }

    l->qtd--;
    
    if (l->qtd == 0){l->last = l->first = NULL;}

    return valor;
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){

    *endereco = *(lista_remover1(l, posicao));

    if(*endereco == NULL){ return false; }

    return true;
}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){

}


No* criar_no(Tipo elemento, ptr ant, ptr prox){

  No* novo = (No*)malloc(sizeof(No));
  novo->ant = ant;
  novo->prox = prox;
  novo->dado = elemento;

  return novo;
}

void busca_no(Lista* l, int posicao, ptr* anterior, ptr* proximo){

  ptr ant;
  ptr prox;

  if (l->qtd == 0){
      return;
  }

  if (posicao >= (l->qtd/2)){
    ant = l->last;
    for(int i = (l->qtd); i > posicao; i--){
      prox = ant;
      ant = ant->ant;
    }
  }

  else{
    prox = l->first;
    for(int i = 0; i < posicao; i++){
      ant = prox;
      prox = ant->prox;
    }
  }

  *anterior = ant;
  *proximo = prox;
}

Boolean lista_buscar(Lista* l, int posicao, int* endereco){
  if (posicao >= l->qtd) return false;

  ptr end;
  busca_no(l, posicao, &end, &end);
  *endereco = end->dado;

  return true;
}

int lista_tamanho(Lista* l){
  return (l->qtd);
}

void lista_imprimir(Lista* l){

  if(l == NULL) {return;}
  if (l->first == NULL){ return;}
  if(l->qtd == 0){printf("Fila vazia!\n"); return;}

  ptr aux = l->first;
  printf("[ ");
  for(int i = 0; i < (l->qtd); i++){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}


//destroi pilha
void lista_destruir(Lista* l){
  //precisa destruir os nós (terceiriza) com recursão
  free(l);
}
