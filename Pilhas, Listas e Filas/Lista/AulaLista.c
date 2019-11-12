#include<stdio.h>
//Lista não tem restrição de inserção e remoção
//Máximo de trabalho é n/2 - porque cada elemento trabalha com dois ponteiros. Que aponta para o anterior e para o próximo. 

typedef struct{
  No* prim;
  No* ult;
  int qtd;
}ListaDupla; 

