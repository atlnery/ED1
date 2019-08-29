#include<stdio.h>
#include <stdlib.h> //necessária para rand - sorteio
#include <time.h> //necessária para srand (sorteio), para não gerar o mesmo valor a cada execução

/*Escreva uma função que crie um vetor preenchido com valores aleatórios.*/

int* preenche_aleatorio(int tam);

int main(){
  int* v1 = preenche_aleatorio(1);
  int* v2 = preenche_aleatorio(100);
}

int* preenche_aleatorio(int tam){
  int* vetor = (int*) calloc(tam, sizeof(int));
  srand(time(NULL));//ESCOLHE UM PERÍODO DE TEMPO PARA GERAÇÃO DE VALORES ALETÓRIOS.
  for (int i = 0; i < tam; i++){
    vetor[i] = rand()%2000;
  }
  return vetor;
}
