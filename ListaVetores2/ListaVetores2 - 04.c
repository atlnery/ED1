/*Escreva uma função que dado um vetor, adicione 1 ao valor de cada elemento.*/

#include<stdio.h>
#include<stdlib.h>

void modificavetor(int* vetor, int tam);

void modificavetor(int* vetor, int tam){
  for (int i = 0; i < tam; i++){
    *(vetor+i) *= 2;
  }
}

int main(){
  int v[6] = {2, 4, 6, 8, 10, 12};
  modificavetor(v, 6);
}
