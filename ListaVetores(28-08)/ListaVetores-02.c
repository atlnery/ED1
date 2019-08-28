#include<stdio.h>
#include<stdlib.h>

int* vetor_return(int tam, int valor);
void vetor_ponteiro(int **v, int tam, int valor);

  int main(){
    //convencional
    printf("CONVENCIONAL\n");
    int i = 5;
    int* v = vetor_return(i, 3);
    printf("[ ");
    for (int j = 0; j < i; j++){
      printf("%d ",v[j]);
    }
    printf("]\n");
    free(v);

    //referência
    printf("PONTEIRO\n");
    i = 6;
    vetor_ponteiro(&v, i, 2);
    printf("[ ");
    for (int j = 0; j < i; j++){
      printf("%d ", v[j]);
    }
    printf("]\n");
    free(v);
  }

  int* vetor_return(int tam, int valor){
    int* v = (int*)malloc(tam);
    for (int i = 0; i < tam; i++){
      *(v+i) = valor;
    }
    return v;
  }

  void vetor_ponteiro(int **v, int tam, int valor){
    *v = (int*)malloc(tam);
    for (int i = 0; i < tam; i++){
    (*v)[i] = valor;
    }
  }
