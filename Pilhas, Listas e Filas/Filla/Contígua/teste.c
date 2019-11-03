#include<stdio.h>
#include<stdlib.h>
#include"FilaCircular.h"

void teste(){

  Fila* f = fila_criar();

  fila_inserir(f, 10); //0  -1
  fila_inserir(f, 15); // 0 - 2
  fila_inserir(f, 20);
  fila_inserir(f, 25);
  fila_inserir(f, 30);
  fila_inserir(f, 35);
  fila_inserir(f, 40);
  fila_inserir(f, 45); //0 -8
  fila_imprimir(f); // 50

  fila_remover1(f);
  fila_remover1(f);
  fila_remover1(f);
  fila_remover1(f);
  fila_remover1(f);
  fila_remover1(f);
  fila_remover1(f); // 7-8
  fila_imprimir(f); // 50


  fila_inserir(f, 50 );
  fila_inserir(f, 100 );

  fila_imprimir(f); // 50

  int x = fila_tamanho(f);
  printf("TAMANHO: %d\n",x);

  fila_primeiro(f, &x);
  printf("PRIMEIRO ELEMENTO: %d\n",x);

  x = fila_contem(f, 15);
  printf("POSIÇÃO ELEMENTO: %d\n",x);
  x = fila_contem(f, 100);
  printf("POSIÇÃO ELEMENTO: %d\n",x);


  fila_remover2(f, &x);
  printf("REMOVIDO: %d\n",x);

  fila_imprimir(f);

  fila_desalocar(f);

  fila_imprimir(f);
}


void main(){
  teste();
}
