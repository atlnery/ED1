#include<stdio.h>
#include<stdlib.h>

int* makevetor(int tam, int valor_inicial);

void main(){
  int *v1;
  v1 = makevetor(5,1);
  printf("[%d, %d, %d, %d, %d] \n",v1[0], v1[1], v1[2], v1[3], v1[4]);
}

int* makevetor(int tam, int valor_inicial){
  int* v = (int*) malloc(4);
  for (int i = 0; i < tam; i++){
    *(v+i) = valor_inicial+i;
  }
  return v;
}
