#include<stdio.h>
#include<stdlib.h>

//NÃO CONSEGUI FAZER COMPLETAMENTE ESSE EXERCÍCIO

int* intercala_a(int* a, int b, int* c, int d);

int main(){

  int v1[3] = {2,4,6};
  int v2[4] = {3,5,7,9};
  int v3[7];
  int *v4;
  v4 = intercala_a(v1, 3, v2, 4);
  /*intercala_b(v1, 3, v2, 4, v3);*/
}

int* intercala_a(int* a, int tam_a, int* b, int tam_b){
  int *vetor = (int*)malloc(7);

  for(int i = 0, j = 0, k = 1; j < tam_b; j++){
    if (tam_b > tam_a){
        *(vetor+i) = *(b+j);
        i+=2;
        vetor[k] = *(a+j);
        k+=2;
        if( j == tam_a){
          *(vetor+i) = *(b+j);
      }
    }
  }
  return vetor;
}
