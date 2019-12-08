#include<stdio.h>
#include<stdlib.h>
#include"matrizesparsa.h"

void teste(){
  int a = 9;
  int b = 7;
  int x;
  Matriz* m = matriz_criar(a, b); //linhas, colunas;

  // for(int i = 0; i < a; i++){
  //   for(int j = 0; j < b; j++){
  //     matriz_atribuir(m, i, j, j);
  //   }
  // }

  matriz_atribuir(m, 0, 0, 1);
  matriz_atribuir(m, 0, 1, 2);
  matriz_atribuir(m, 0, 2, 3);
  matriz_atribuir(m, 0, 3, 4);
  matriz_atribuir(m, 0, 4, 5);
  matriz_atribuir(m, 0, 5, 6);
  matriz_atribuir(m, 0, 4, 7);
  matriz_atribuir(m, 0, 6, 7);


  matriz_imprimir(m);
}

void main(){
  teste();
}
