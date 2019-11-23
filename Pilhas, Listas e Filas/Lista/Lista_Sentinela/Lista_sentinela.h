#include<stdio.h>
#include<stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;
typedef struct no* ptr;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* sentinela;
    int qtd;
}Lista;


Lista* lista_criar(); //cria a struct lista com sentinela
No* criar_no(Tipo elemento, ptr aux); //cria os nós da lista
void lista_destruir(Lista* l);
void destroi_no(ptr no, ptr aux, Lista* l);

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao); //insere o elemento na posição passada por parametro.

int* lista_remover1(Lista* l, int posicao); //REMOVE O ELEMENTO E GRAVA O ENDEREÇO DO VALOR REMOVIDO
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);//remove o elemento e guarda o valor em variável
Boolean lista_remover_elemento(Lista* l, Tipo elemento);

Boolean lista_buscar(Lista* l, int posicao, ptr* endereco); //grava o endereco e afirma se tem ou não
Boolean lista_contem(Lista* l, Tipo elemento); //informa se o valor está na lista
int lista_posicao(Lista* l, Tipo elemento); //devolve a posição do elemento na lista

int lista_tamanho(Lista* l); //devolve ao usuário o tamanho da lista
Boolean lista_imprimir(Lista* l);//imprime elementos da lista

void tipo_busca(Lista* l, Tipo* a, Tipo* b);

Lista* lista_criar(){

  Lista* lista = (Lista*)malloc(sizeof(Lista));
  lista->qtd = 0;

  No* no = (No*)malloc(sizeof(No));
  no->prox = no->ant = no;

  lista->sentinela = no;

  return lista;
}

No* criar_no(Tipo elemento, ptr aux){

  No* novo = (No*)malloc(sizeof(No));
  novo->ant = aux;
  novo->prox = aux->prox;
  novo->dado = elemento;

  return novo;
}

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){
  if (posicao > l->qtd) return false;

  ptr aux;
  lista_buscar(l, posicao, &aux);

  No* no = criar_no(elemento, aux);
  aux->prox->ant = no;
  aux->prox = no;
  l->qtd++;

  return true;
}

Boolean lista_buscar(Lista* l, int posicao, ptr* endereco){
  if(posicao > l->qtd) return false;

  *endereco = l->sentinela;
  int a, b;

  if(l->qtd/2 < posicao){
    a = l->qtd; b = posicao;
    for(int i = a; i >= b; i--){
      *endereco = (*endereco)->ant;
    }
  }
  else{
  a = 0; b = posicao;
    for(int i = a; i < b; i++){
      *endereco = (*endereco)->prox;
    }
  }
  return true;
}

Boolean lista_contem(Lista* l, Tipo elemento){
  int a = lista_posicao(l,  elemento);

  if (a == -1){
    return false;
  }
  else{
    return true;
  }
}

int lista_posicao(Lista* l, Tipo elemento){

  ptr aux = l->sentinela->prox;
  int pos = -1;
  for(int i = 0 ; i < l->qtd; i++){
    if(aux->dado == elemento){
      pos = i;
      break;
    }
    aux = aux->prox;
  }
  return pos;
}

int lista_tamanho(Lista* l){
  return l->qtd;
}

int* lista_remover1(Lista* l, int posicao){
  if(posicao >= l->qtd) return NULL;
  if(l->qtd == 0) return NULL;

  ptr aux;

  lista_buscar(l, posicao, &aux);

  aux = aux->prox;

  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  int* valor = &aux->dado;
  l->qtd--;

  return valor;
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
  if(posicao >= l->qtd) return false;
  if(l->qtd == 0) return false;

  ptr aux;
  lista_buscar(l, posicao, &aux);
  aux= aux->prox;

  lista_remover1(l, posicao);
  *endereco = aux->dado;

  return true;
}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){
  if(l->qtd == 0)return false;

  int pos = lista_posicao(l, elemento);
  if(pos == -1) return false;

  lista_remover1(l, pos);
}

Boolean lista_imprimir(Lista* l){
  if(l->qtd == 0) return false;

  ptr aux = l->sentinela->prox;
  printf("\n[ ");
  for(int i = 0; i < l->qtd; i++){
    printf("%d ",aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void lista_destruir(Lista* l){
  if(l->qtd != 0){
    destroi_no(l->sentinela, l->sentinela->prox, l);
  }
  free(l);
}

void destroi_no(ptr no, ptr aux, Lista* l){
  while (l->qtd != 0){
    free(no);
    no = aux;
    aux = aux->prox;
    l->qtd--;
  }
}
