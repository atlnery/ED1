/*Escreva uma função que dado um vetor, adicione 1 ao valor de cada elemento.*/

#include<stdio.h>
#include<stdlib.h>

int modificavetor(int *vetor, int tam);
  vetor = (int*) malloc(tam);
  
}

int main(){
  int v[4] = {6, 7, 8, 9};
  modificavetor(v, 4);
  printf("%d, %d, %d, %d\n", v[0], v[1], v[2], v[3]);
}
