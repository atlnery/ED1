#include<stdio.h>
#include<stdlib.h>

int vetor_dobraTamanho(int** vetor, int tam);

int main(){
  int* v = (int*) calloc(3, sizeof(int));
  v[0] = 2;
  v[1] = 4;
  v[2] = 6;
  /*printf("endereço de v %d\n",&v);
  printf("%d\n",v);
  printf("%d\n",&v[0]);*/
  int novoTamanho = vetor_dobraTamanho(&v,3);
  
  free(v);
}

int vetor_dobraTamanho(int** vetor, int tam){
  int* novo = (int*) calloc((2*tam), sizeof(int));
  for (int i = 0; i < tam; i++){
    novo[i] = *(*vetor+i);
  }
  return sizeof(novo);//sizeof do NOVO vetor mesmo?
}
