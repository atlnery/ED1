#include<stdio.h>
#include<stdlib.h>
#include "Lista_sentinela.h"


void teste(){

  int tf; int value;

  Lista* l = lista_criar();

  tf = lista_inserir(l, 1, 0); //printf("%d",tf);
  tf = lista_inserir(l, 2, 0); //printf("%d",tf);
  tf = lista_inserir(l, 3, 0); //printf("%d",tf);
  tf = lista_inserir(l, 4, 0); //printf("%d",tf);
  tf = lista_inserir(l, 5, 0); //printf("%d",tf);
  tf = lista_inserir(l, 6, 1); //printf("%d",tf);
  tf = lista_inserir(l, 7, 2); //printf("%d",tf);
  tf = lista_inserir(l, 8, 3); //printf("%d",tf);
  tf = lista_inserir(l, 9, 0); //printf("%d",tf);


  ptr endereco;
  tf = lista_buscar(l, 5, &endereco);
  printf("TEM ELEMENTO GRAVADO EM POSIÇÃO? %d\n",tf );

  printf("VALOR %d\n",endereco->prox->dado);

  value = lista_posicao(l, 5);
  printf("POSIÇÃO DO VALOR 1? %d\n",value);

  tf = lista_contem(l, 5);
  printf("CONTEM ELEMENTO? %d\n",tf );

  value = lista_tamanho(l); printf("TAMANHO LISTA? %d\n",value);

  lista_imprimir(l);
  int* removido = lista_remover1(l, 8);
  printf("REMOVIDO? %d\n",*removido);
  lista_imprimir(l);

  tf = lista_remover2(l, 3, &removido);
  printf("REMOVIDO? %d\n", removido);
  lista_imprimir(l);

  tf = lista_remover_elemento(l, 6);

  lista_destruir(l);

  lista_imprimir(l);
}

void main(){
  teste();
}
