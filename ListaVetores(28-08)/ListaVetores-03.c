#include<stdio.h>
#include<stdlib.h>

int* make_vetor(int tam, int valor);
int verifica_indice(int* elemento, int** vetor, int tam);


int main(){
  int *v;
  v = make_vetor(4, 3);
  int elemento;
  verifica_indice(&elemento,&v, 4);
  printf("Elemento %d = %d \n",elemento, v[elemento]);
}

int* make_vetor(int tam, int valor){
  int *v = (int*)malloc(tam);
  for(int i = 0; i < tam; i++){
    *(v+i) = valor*i;
  }
  return v;
}

int verifica_indice(int* elemento, int** vetor, int tam){
  int maior = (*vetor)[0];
  for (int i = 0; i < tam; i++){
    if ((*vetor)[i] > maior){
      *elemento = i;
    }
  }
}
