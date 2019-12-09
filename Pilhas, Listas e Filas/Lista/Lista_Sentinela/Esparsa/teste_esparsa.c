#include<stdio.h>
#include<stdlib.h>
#include"matrizesparsa.h"

void teste(){
  int a = 6; int b = 5; //a - linhas, b - colunas
  int x; //x - informação de retorno das funções
  Matriz* m = matriz_criar(a, b); //linhas, colunas;

  //ATRIBUIÇÃO GERAL
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      matriz_atribuir(m, i, j, j);
    }
  }
  matriz_imprimir(m);

  //ATRIBUIÇÃO PONTUAL
  matriz_atribuir(m, 0, 0, 1);
  matriz_atribuir(m, 0, 1, 2);
  matriz_atribuir(m, 0, 2, 3);
  matriz_atribuir(m, 0, 3, 4);
  matriz_atribuir(m, 0, 4, 5);
  matriz_atribuir(m, 1, 4, 5);

  x = matriz_acessar(m, 1, 7);
  printf("Elemento: %d\n",x);
  x = matriz_acessar(m, 1, 17);
  printf("Elemento: %d\n",x);
  x = matriz_acessar(m, 0, 1);
  printf("Elemento: %d\n",x);


  matriz_desalocar(m);
  //matriz_imprimir(m);
}

void main(){
  teste();
}
