/*Escreva uma função que dado um vetor, adicione 1 ao valor de cada elemento.*/

#include<stdio.h>
#include<stdlib.h>

void modificavetor(int* vetor, int tam);

void modificavetor(int* vetor, int tam){
  for (int i = 0; i < tam; i++){
    *(vetor+i) += 1;
  }
}

int main(){
  int v[4] = {6, 7, 8, 9};
  modificavetor(v, 4);
}
