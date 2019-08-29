#include<stdio.h>
#include<stdlib.h>
/*
Escreva uma função que crie um clone de um determinado vetor. Desenvolva duas versões desta
função:
a) usando a estratégia convencional
b) usando a estratégia do scanf.*/

int* makeclone(int* v, int tam);
int makeclone2(int* orginal, int* copia, int tam);

int* makeclone(int* v, int tam){
  int* clone = (int*) malloc(tam);
  for(int i = 0; i < tam; i++){
    clone[i] = v[i];
  }
  return clone;
}

int makeclone2(int* original, int* copia, int tam){
  copia = (int*) malloc(tam);
  for (int i = 0; i < tam; i ++){
    copia[i] = original[i];
  }
}

int main(){
  printf("RETURN\n");
  int v[4] = {2,3,4,5};
  int* vclone = makeclone(v,4);

  printf("SCANF\n");
  int* vclone2;
  makeclone2(v, vclone2, 4);
}
